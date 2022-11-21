#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h> 
#include <sys/stat.h>

//sender
int main(){
    int n;
    char buffer[100];
    int res = mkfifo("fifo1", 0666);
    char str1[100];
    printf("fifo1 created\n");
    printf("Enter string to write: ");
    fgets(str1,100,stdin);
    res = open("fifo1",O_RDWR);
    write(res,str1,100);
    res = open("fifo2", O_RDWR);
    read(res,buffer,100);
    printf("printing data received from fifo2 %s\n",buffer);
    return 0;
}