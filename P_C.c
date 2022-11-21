#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

// gcc filename.extension -lpthread -lrt

#define buffer_size 10

sem_t full, empty;
int buffer[buffer_size];

pthread_mutex_t mutex;

int counter;

void initialize(){
    pthread_mutex_init(&mutex, NULL);
    sem_init(&full, 1, 0);
    sem_init(&empty, 1, buffer_size);
    counter = 0;
}

void insertItem(int item){
    buffer[counter++] = item;
}

int remove_item(){
    return (buffer[--counter]);
}

void *producer(void *p){
    sleep(3);
    int item = rand() % 10;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    printf("\n Producer produced %d item", item);
    insertItem(item);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void *consumer(void *p){
    sleep(6);
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    int item = remove_item();
    printf("\n Consumer consumed %d item", item);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main(){
    int nP, nC, i;
    printf("Enter no. of producers you want to create:");
    scanf("%d", &nP);
    printf("Enter no. of consumers you want to create:");
    scanf("%d", &nC);

    initialize();

    pthread_t tid[nP], tid1[nC];

    for (i = 0; i < nP; i++){
        pthread_create(&tid[i], NULL, producer, NULL);
    }
    for (i = 0; i < nC; i++){
        pthread_create(&tid1[i], NULL, consumer, NULL);
    }
    sleep(10);
    exit(0);
}
