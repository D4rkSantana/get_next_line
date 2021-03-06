#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static void     ft_strdel(char **pont){
	if (pont != NULL)
	{
		free(*pont);
		*pont = NULL;
	}
}

static int      linebreak(char * str){
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

static void     *ft_calloc(size_t count, size_t size){
	char 	*str;
    size_t  x;

    x = 0;
	if (!(str = malloc(count * size)))
		return (0);
	while (x < (count * size))
	{
		str[x] = 0;
		x++;
	}
	return ((void *)str);
}

static size_t	ft_strlen(const char *s){
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize){
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

    /**
     * essa função é um strjoin modificado, ele copia somente a quantidade passada no segundo
     * parametro e da free em s1
    **/
	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size = size1 + size2 + 1;
	if (!(new = (char *)calloc(sizeof(char), size)))
		return (NULL);
	ft_strlcpy(new, s1, size1 + 1); 
	ft_strlcpy(new + size1, s2, size2 + 1);
	ft_strdel(&s1);
	return (new);
}

static char     *ft_strindexcpy(char **save, char * str, size_t index){
	size_t  count;
	char    *dst;

    /**
     * Essa função é uma junção da ft_strlcpy e ft_strjoin
     * ele começa a copiar depois do index passado
     * ele tambem aloca memoria para retornar o resultado
    **/
	count = 0;
	dst = (char *)calloc(sizeof(char), ft_strlen(str) - (index));
	while (count < ft_strlen(str) && index < ft_strlen(str)){
	    dst[count] = str[index];
	    index++;
	    count++;
	}
    dst[count] = '\0';
    *save = dst;
	return (dst);
}

static int      get_line(int fd, char *save, char **temp){
    int         return_read;
    char        *buff;
    char        *line;

    buff = (char *)calloc(sizeof(char), BUFFER_SIZE + 1);
    line = (char *)calloc(sizeof(char), BUFFER_SIZE + 1);
    if ((!(buff)) || (!(line)))
        return (-1);
    buff[BUFFER_SIZE] = '\0';
    line[BUFFER_SIZE] = '\0';
    return_read = 1;
    if (save == NULL)
        return_read = read(fd, line, BUFFER_SIZE);
    else{
        ft_strlcpy(line, save, ft_strlen(save) + 1);
    }
    while (linebreak(line) == -1 && return_read > 0)
    {
        return_read = read(fd, buff, BUFFER_SIZE);
        if (return_read == -1)
            return (-1);
        //buff[return_read] = '\0';
        if (return_read > 0)
            line = ft_strjoin_free1(line, buff, return_read);
    }
    ft_strdel(&buff);
    *temp = line;
    return (return_read);
}

static char     *get_result(int r_read, char *temp, char **save){
    char *line;
    int index;

    if (r_read > 0)
        index = linebreak(temp);
    else {
        index = ft_strlen(temp);
    }
    if (linebreak(temp) != -1){
        if (save != NULL)
        ft_strdel(save);
        *save = ft_strindexcpy(save, temp, index + 1);
        //save[index] = '\0';
    }
    if (!(line = (char *)calloc(sizeof(char), index + 1)))
        return (NULL);
    ft_strlcpy(line, temp, index + 1);
    return(line);
}

static int      get_next_line(int fd, char **line){
    static char *save;
    char        *temp;
    int         return_read;

    //incio
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
    //meio
    printf("\n------>save = %s|\n", save);
    return_read = get_line(fd, save, &temp);
    if (return_read == -1)
        return (-1);
    *line = get_result(return_read, temp, &save);
    //fim
    if (*line == NULL)
        return (-1);
    ft_strdel(&temp);
    if (return_read == 0){
        ft_strdel(&save);
        return (0);
    }
    return(1);
}

int             main(){
    int fd;
    int retorno;
    char *line;

    retorno = 1;
    fd = open("texto.txt", O_RDONLY);
    while(retorno > 0){
        retorno = get_next_line(fd, &line);
        printf("Resultado: %s|\n", line);
        printf("Retorno: %d\n==========\n", retorno);
    }
    //printf("Resultado final: %s|", line);
    close(fd);
    return (0);
}