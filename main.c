#include "get_next_line.h"

int main(){
    int fd;
    char *line;

    *line = 0;
    fd = open("texto.txt", O_RDONLY);
    //while()
    get_next_line(fd, &line);
    printf("Resultado final: %s|", line);
    close(fd);
    return (0);
}