/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:42:10 by esilva-s          #+#    #+#             */
/*   Updated: 2021/02/15 16:52:24 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
/*
static void save(){
    //=========================================
    //Essa função salva o restante de um buffer
    //ou retorna o que ja foi salvo anteriormente
    //=========================================
    satatic char * save;

}
*/

int get_next_line(int fd){
    size_t  resultado;
    char    * buff;
    char    * buff_line;
    char    * save;
    int     x;
    int     i;

    //=========================================
    //Alocação do buff e leitura
    //=========================================
    x = 40;
    //save = 0;
    buff = malloc(sizeof(char) * x);
    resultado = read(fd, buff, x);
    printf("------------\nRetorno read: %ld\n------------", resultado);

    //=========================================
    //Pesquisa da posição da primeira quebra de linha
    //=========================================
    i = linebreak(buff);
    printf("\nRetorno do linebreak: %d", i);
    save = ft_strindexcpy(buff, i);

    //=========================================
    //Alocação da memoria para o buff de linha e copia
    //=========================================
    buff_line = malloc(sizeof(char) * i);
    ft_strlcpy(buff_line, buff, i + 1);//ssss

    //=========================================
    //Apresentação dos valores
    //=========================================
    printf("\nStrlen do buff: %ld", ft_strlen(buff));
    printf("\nStrlen do buff_line: %ld", ft_strlen(buff_line));
    printf("\nStrlen do save: %ld\n------------", ft_strlen(save));
    printf("\nBuff: %s|", buff);
    printf("\nBuff_line: %s|", buff_line);
    printf("\nSave: %s|\n------------\n", save);

    //=========================================
    //Finalização
    //=========================================
    free (buff);
    free (buff_line);
    free (save);
    return (resultado);
}