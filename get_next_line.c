/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:42:10 by esilva-s          #+#    #+#             */
/*   Updated: 2021/02/04 14:03:42 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int get_next_line(int fd, char **line){

    int             BUFFER_SIZE;
    int             read_return;
    char            *;
    char static     *temp;

    BUFFER_SIZE = 32;
    read_return = 1;
    // Tratamento de erro
    if (fd <= 0 || BUFFER_SIZE <= 0)
        return (-1);
    if (!(buff = malloc((sizeof(char) * 32) + 1)))
        return (-1);
    //
    //read(fd, buff, BUFFER_SIZE);
    //buff[BUFFER_SIZE] = '\0';
    //*line = buff;
    while(){

    }
    return (0);
}