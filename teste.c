/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:52:01 by esilva-s          #+#    #+#             */
/*   Updated: 2023/06/24 23:08:01 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int     fd;
    char    *line;

    line = NULL;
    fd = open("docs/teste.txt", O_RDONLY);
    if (fd == -1)
        return (0);
    while (get_next_line(fd, &line))
    {
        printf("%s\n", line);
    }
    close(fd);
    return (0);
}
