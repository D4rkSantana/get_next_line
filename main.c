#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static int  linebreak(char * str){
    int     count;

    /**
     * Esse programa retorna o index de onde esta o \n
     * com o padrão de 0 - 10
     * 
     * caso não exista um \n ele retorna -1
    **/
    count = 0;
    while (str[count])
    {
        if(str[count] == '\n')
            return (count);
        count++;
    }
    return (-1);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = 0;
	if (!dst)
		return (0);
	while (src[len] != '\0')
		len++;
	if (!dstsize)
		return (len);
	while (src[count] && count < dstsize - 1)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (len);
}

static char		*ft_strjoin_free1(char *s1, char const *s2, size_t size2){
	unsigned int	size;
	unsigned int	size1;
	char			*new;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size = size1 + size2 + 1;
	if (!(new = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strlcpy(new, s1, size1 + 1); 
	ft_strlcpy(new + size1, s2, size2 + 1);
	free(s1);
	return (new);
}

static char *ft_strindexcpy(char **save, char * str, size_t index){
	size_t  count;
	char    *dst;

	count = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) - (index + 1)));
	while (count < ft_strlen(str) && index < ft_strlen(str)){
	    dst[count] = str[index];
	    index++;
	    count++;
	}
    dst[count + 1] = '\0';
    *save = dst;
	return (dst);
}

static int      get_line(int fd, char *save, char **temp){
    int         return_read;
    char        *buff;
    char        *line;

    buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    return_read = 1;
    if (save == NULL)
        return_read = read(fd, line, BUFFER_SIZE);
    else{
        ft_strlcpy(line, save, ft_strlen(save));
    }
    printf("\n----\npre-loop\n");
    printf("pre-line: %s\n", line);
    while (linebreak(line) == -1 && return_read > 0)
    {
        printf("\nloop\n");
        return_read = read(fd, buff, BUFFER_SIZE);
        if (return_read == -1)
            return (-1);
        if (return_read > 0)
            line = ft_strjoin_free1(line, buff, return_read);
        printf("loop-line: %s\n", line);
    }
    free(buff);
    printf("\nend\n");
    printf("end-line: %s\n", line);
    *temp = line;
    return (return_read);
}

static char     *get_result(char *temp, char **save){
    char *line;
    int index;

    index = linebreak(temp);
    if (index != -1)
        if (save != NULL)
        free(*save);
        *save = ft_strindexcpy(save, temp, index + 1);
    line = (char *)malloc(sizeof(char) * (index + 1));
    ft_strlcpy(line, temp, index + 1);
    return(line);
}

static int      get_next_line(int fd, char **line){
    static char *save;
    char        *temp;
    char        *result;
    int         count;
    int         return_read;

    count = 0;
    return_read = get_line(fd, save, &temp);
    if (return_read == -1)
        return (-1);
    if (save != NULL){
        while (save[count]){
            save[count] = '\0';
            count++;
        }
    }
    *line = get_result(temp, &save);
    //printf("\nTemp: %s=\n", temp);
    //printf("\nSave: %s=\n", save);
    free(temp);
    if (return_read == 0){
        free(save);
        return (0);
    }
    return(return_read);
}

int main(){
    int fd;
    int retorno;
    char *line;

    retorno = 1;
    fd = open("texto.txt", O_RDONLY);
    while(retorno > 0){
        retorno = get_next_line(fd, &line);
        //printf("Resultado: %s|\n", line);
        //printf("Retorno: %d\n==========\n", retorno);
    }
    //printf("Resultado final: %s|", line);
    close(fd);
    return (0);
}