#include "get_next_line.h"

int main(){
    char    * str;
    char    * str2;
    int     index;
    int     size2;

    str = (char *)malloc(sizeof(char) * 21);
    ft_strlcpy(str, "abcdefghij\n123456789aaaa", 21);
    printf("\nStr: %s|\n", str);

    index = linebreak(str);

    printf("\nLine Break: %d|\n", index);

    size2 = ft_strlen(str) - index;
    printf("\nSize 2: %d|\n", size2);
    str2 = (char *)malloc(sizeof(char) * size2);
    str2 = ft_strindexcpy(str, index);
    printf("\nStr 2: %s|\n", str2);
}