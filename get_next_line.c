/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:42:10 by esilva-s          #+#    #+#             */
/*   Updated: 2021/02/26 15:51:32 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

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
            return (count + 1);
        count++;
    }
    return (-1);
}

static char *ft_strindexcpy(char **save, char * str, size_t index){
	size_t  count;
	char    *dst;

    /**
     * Semelhante ao ft_strncpy, porem copia a partir
     * da posição indicada e aloca espaço.
     * 
     * recebe o index no padrão 1 - 10
     * 
     * retorna o ponteiro da string que recebeu o conteudo
    **/
	count = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) - index));
	while (count < ft_strlen(str) && index < ft_strlen(str)){
	    dst[count] = str[index];
	    index++;
	    count++;
	}
    dst[count] = '\0';
    if (save != NULL)
        free(*save);
    *save = dst;
	return (dst);
}

static int  get_result(int return_read, char *buff_total, char **r){
    int     index_n;
    char    *result;

    if (return_read >= 1)
        index_n = linebreak(buff_total);
    else {
        index_n = ft_strlen(buff_total) + 1;
    }
    if (!(result = (char *)malloc(sizeof(char) * index_n + 1)))
        return (-1);
    ft_strlcpy(result, buff_total, index_n);

    *r = result;
    return (index_n);
}

static int  get_line(int fd, const char *save, char **bf_t){
    int     return_read;
    char    *buff;
    char    *buff_total;

    if (!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE )))
        return (-1);
    return_read = 1;
    if (save != NULL){
        ft_strlcpy(buff, save, ft_strlen(save) + 1);
        buff_total = ft_strdup(buff);
    } else {
        return_read = read(fd, buff, BUFFER_SIZE);
        buff_total = ft_strdup(buff);
    }
    while (linebreak(buff_total) == -1 && return_read > 0){
        free(buff);
        if (!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
            return (-1);
        return_read = read(fd, buff, BUFFER_SIZE);
        if (return_read >= 1)
            buff_total = ft_strjoin_free1(buff_total, buff, return_read);
    }
    free(buff);
    *bf_t = buff_total;
    return (return_read);
}

int             get_next_line(int fd, char **line){
    static char *save;
    char        *buff_total;
    char        *result;
    int         return_read;
    int         index_n;

    
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
    if ((return_read = get_line(fd, save, &buff_total)) < 0)
        return (-1);
    if ((index_n = get_result(return_read, buff_total, &result)) < 0)
        return (-1);
    if (return_read > 0)
        ft_strindexcpy(&save, buff_total, index_n);
    *line = result;
    if (return_read == 0){
        *save = 0;
        return (0);
    }
    return (1);
}