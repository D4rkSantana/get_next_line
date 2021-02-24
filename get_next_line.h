/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:42:39 by esilva-s          #+#    #+#             */
/*   Updated: 2021/02/24 09:27:33 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int get_next_line(int fd, char **line);

//int get_next_line_teste(int fd);

int  linebreak(char * str);

char *ft_strindexcpy(const char * str, size_t index);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlen(const char *s);

char    *ft_strjoin_free1(char *s1, char const *s2, size_t sz2);

char	*ft_strdup(const char *s1);

#endif