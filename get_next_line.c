/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:42:10 by esilva-s          #+#    #+#             */
/*   Updated: 2021/02/12 12:44:17 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int get_next_line(int fd, char **line){
    char    * buff;
    size_t  result;
    int     count;
    
    if(fd == 0)
        return (-1);
    if(!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
        return (-1);
    result = read(fd, buff, BUFFER_SIZE);
    count = 0;
    while (buff[count] != '\0'){
        if(buff[count] == '\n')
            break;
        count++;
    }
    return (0);
}