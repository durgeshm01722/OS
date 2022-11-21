#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
// sender
int count_char(char *str){
    int i = 0, chars = 0;
    while (str[i] != '\0'){
        if (str[i] != ' ' && str[i] != '\n'){
            chars++;
        }
        i++;
    }
    return chars;
}

int count_word(char *str){
    int i = 0, wrd = 0;
    while (str[i] != '\0'){
        if (str[i] == ' ' || str[i] == '\n' || str[i] == 't'){
            wrd++;
        }
        i++;
    }
    return wrd;
}

int count_lines(char *str){
    int i = 0, lines = 0;
    while (str[i] != '\0'){
        if (str[i] == '\n'){
            lines++;
        }
        i++;
    }
    return lines;
}

char *int_to_string(int num){
    char *str = (char *)malloc(10);
    sprintf(str, "%d", num);
    return str;
}

int main(){
    int res, n, ct1, ct2, res2, ct3;
    char buffer[100];
    char str[100];
    FILE *file;
    char *tt1, *tt2, *tt3;
    char cha[50] = "Characters are: ";
    char words[50] = " and words are ";
    char lines[50] = " lines are :";
    res = mkfifo("fifo2", 0666);printf("fifo2 created\n");
    res = open("fifo1", O_RDWR);
    read(res, buffer, 100);
    ct1 = count_char(buffer);
    ct2 = count_word(buffer);
    ct3 = count_lines(buffer);
    res2 = open("fifo2", O_RDWR);
    strcat(cha, int_to_string(ct1));
    strcat(cha, words);
    strcat(cha, int_to_string(ct2));
    strcat(cha, lines);
    strcat(cha, int_to_string(ct3));
    write(res2, cha, 100);
    // write(res2,tt2,100);
    return 0;
}