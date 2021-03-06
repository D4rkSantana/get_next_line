#include "get_next_line.h"

char    *ft_strjoin_free1(char *s1, char const *s2, size_t size2){
	unsigned int	size;
	unsigned int	size1;
	char			*new;

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

char    *ft_strindexcpy(char **save, char * str, size_t index){
	size_t  count;
	char    *dst;

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

int     get_line(int fd, char *save, char **temp){
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
    while (ft_linebreak(line) == -1 && return_read > 0)
    {
        return_read = read(fd, buff, BUFFER_SIZE);
        if (return_read == -1)
            return (-1);
        if (return_read > 0)
            line = ft_strjoin_free1(line, buff, return_read);
    }
    ft_strdel(&buff);
    *temp = line;
    return (return_read);
}

char    *get_result(int r_read, char *temp, char **save){
    char *line;
    int index;

    if (r_read > 0)
        index = ft_linebreak(temp);
    else {
        index = ft_strlen(temp);
    }
    if (ft_linebreak(temp) != -1){
        if (save != NULL)
        ft_strdel(save);
        *save = ft_strindexcpy(save, temp, index + 1);
    }
    if (!(line = (char *)calloc(sizeof(char), index + 1)))
        return (NULL);
    ft_strlcpy(line, temp, index + 1);
    return(line);
}

int     get_next_line(int fd, char **line){
    static char *save;
    char        *temp;
    int         return_read;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
    return_read = get_line(fd, save, &temp);
    if (return_read == -1)
        return (-1);
    *line = get_result(return_read, temp, &save);
    if (*line == NULL)
        return (-1);
    ft_strdel(&temp);
    if (return_read == 0){
        ft_strdel(&save);
        return (0);
    }
    return(1);
}