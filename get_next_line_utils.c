/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:57:52 by esilva-s          #+#    #+#             */
/*   Updated: 2021/03/08 16:07:21 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_strdel(char **pont)
{
	if (pont != NULL)
	{
		free(*pont);
		*pont = NULL;
	}
}

int			ft_linebreak(char *str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}

void		*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	x;

	x = 0;
	if (!(str = malloc(count * size)))
		return (0);
	while ((x < (count * size)) && (x < 10))
	{
		str[x] = 0;
		x++;
	}
	return ((void *)str);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
