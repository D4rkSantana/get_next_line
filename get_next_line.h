/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:42:39 by esilva-s          #+#    #+#             */
/*   Updated: 2021/03/06 15:53:25 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int     ft_linebreak(char * str);
void    ft_strdel(char **pont);
void    *ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char    *ft_strjoin_free1(char *s1, char const *s2, size_t size2);
char    *ft_strindexcpy(char **save, char * str, size_t index);
char    *get_result(int r_read, char *temp, char **save);
int     get_line(int fd, char *save, char **temp);
int     get_next_line(int fd, char **line);





char    *ft_strjoin_free1(char *s1, char const *s2, size_t sz2);

#endif