#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int fd;
    char *line;

    fd = open("texto.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n", line);
    close(fd);
    free(line);
    return (0);
}