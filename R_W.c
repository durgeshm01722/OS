#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
sem_t writer;
pthread_t rdr[100], wtr[100];

int readcount = 0, nW, nR;

void *reader_thr(int temp){
    printf("\nReader %d is trying to enter database for reading.", temp);
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1){
        sem_wait(&writer);sem_post(&mutex);
    }
    printf("\nReader %d is now reading in database.", temp);
    sem_wait(&mutex);
    readcount--;
    if (readcount == 0){
        sem_post(&writer);
    }
    sem_post(&mutex);
    printf("\nReader %d has left the database.\n", temp);
    sleep(3);
}

void *writer_thr(int temp){
    printf("\nWriter %d is trying to enter database for modifying data", temp);
    sem_wait(&writer);
    printf("\nWriter %d is writing in database.", temp);
    sleep(3);
    printf("\nWriter %d is leaving the database.\n", temp);
    sem_post(&writer);
}

void initialize(){
    sem_init(&mutex, 0, 1);
    sem_init(&writer, 0, 1);
}

void main(){
	initialize();
    printf("\nEnter number of readers:");
    scanf("%d", &nR);
    printf("\nEnter number of writers:");
    scanf("%d", &nW);
    for (int i = 1; i <= nW; i++){
        pthread_create(&wtr[i], NULL, (void *)writer_thr, (int *)i);
        pthread_join(wtr[i], NULL);
    }
    for (int i = 1; i <= nR; i++){
        pthread_create(&rdr[i], NULL, (void *)reader_thr, (int *)i);
        pthread_join(rdr[i], NULL);
    }
    sem_destroy(&writer);
    sem_destroy(&mutex);
}
