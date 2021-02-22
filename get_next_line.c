/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:42:10 by esilva-s          #+#    #+#             */
/*   Updated: 2021/02/22 14:08:43 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static int  linebreak(char * str){
    int     count;

    count = 0;
    while (str[count])
    {
        if(str[count] == '\n')
            return (count + 1);
        count++;
    }
    return (-1);
}

static char *ft_strindexcpy(const char * str, size_t index){
	size_t  count;
	char    *dst;

	count = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) - index));
	while (count < ft_strlen(str) && index < ft_strlen(str)){
	    dst[count] = str[index];
	    index++;
	    count++;
	}
    dst[count] = '\0';
	return (dst);
}

static int  get_result(int return_read, char *buff_total, char **r){
    int     index_n;
    char    *result;
    
    //printf("\nEXQUEREEEEEE\n");
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

    if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
    return_read = 1;
    //printf("\nSAVE: %s\n", save);
    if (save != NULL){
        ft_strlcpy(buff, save, ft_strlen(save) + 1);
        buff_total = ft_strdup(buff);
        //printf("\n======AAAA\n");
    } else {
        return_read = read(fd, buff, BUFFER_SIZE);
        buff_total = ft_strdup(buff);
        //printf("\n======BBBB\n");
        //printf("\nBUFF: %s\n", buff);
        //printf("\nBUFF_TOTAL: %s\n", buff_total);
    }
    while (linebreak(buff_total) == -1 && return_read > 0){
        free(buff);
        if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
            return (-1);
        return_read = read(fd, buff, BUFFER_SIZE);
        //printf("\n====BUFF: %s\n", buff);
        //printf("====BUFF_TOTAL: %s\n", buff_total);
        if (return_read >= 1)
            buff_total = ft_strjoin_free1(buff_total, buff, return_read);
    }
    //*bf = buff;
    free(buff);
    *bf_t = buff_total;
    return (return_read);
}

int             get_next_line(int fd, char **line){
    static char *save;
    //char        *buff;
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
        save = ft_strindexcpy(buff_total, index_n);
    //free(buff_total);
    //printf("\n======Result: %s\n", result);
    //printf("======Return_read: %d\n", return_read);
    *line = result;
    if (return_read == 0){
        *save = 0;
        return (0);
    }
    return (1);
}