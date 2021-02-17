#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd;
    int result;
    int size;
    char * buff;

    result = 1;
    size = 10;
    fd = open("texto.txt", O_RDONLY);
    buff = malloc(sizeof(char) * size);
    printf("\n-------\n");
    while(result){
        result = read(fd, buff, size);
        printf("Buff: %s\n", buff);
        printf("Result: %d\n-------\n", result);
    }
    close(fd);
    return(0);
}