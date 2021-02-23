#include "get_next_line.h"

int main(){
    char * str;
    int size;

    size = 21;
    str = (char *)malloc(sizeof(char) * 20);
    ft_strlcpy(str, "abcdefghij\naaaaaaaaa", size);
    printf("\nStr: %s|\n", str);
    size = linebreak(str);
    printf("\nlineB: %d|\n", size);
}