#include "get_next_line.h"

int main(){
    int fd;
    int retorno;
    char *line;

    *line = 0;
    retorno = 1;
    fd = open("texto.txt", O_RDONLY);
    while(retorno){
        retorno = get_next_line(fd, &line);
        printf("Resultado: %s|\n", line);
        printf("Retorno: %d\n==========\n", retorno);
    }
    //printf("Resultado final: %s|", line);
    close(fd);
    return (0);
}