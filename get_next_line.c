/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:42:10 by esilva-s          #+#    #+#             */
/*   Updated: 2021/02/16 16:48:50 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static int  linebreak(char * str){
    int count;

    //=========================================
    //Faz a leitura até achar a quebra de linha
    // e retorna a posição
    //=========================================
    count = 0;
    while (str[count])
    {
        if(str[count] == '\n')
            return (count + 1);
        count++;
    }
    return(-1);
}

static char * ft_strindexcpy(const char * str, size_t index){
	int count;
	int size;
	char * dst;

	//=========================================
	//Essa função copia uma string a partir do
	//index passado até o fim
	//=========================================
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

int get_next_line(int fd, char **line){
    static char * save;
    char        * buff;
    char        * buff_total;
    char        * result;
    int         return_read;
    int         index_n;
    int         buffer_size;

    buffer_size = 32;
    return_read = 1;
    if(!(buff = malloc(sizeof(char) * buffer_size)))
        return (-1);

    //confirma se existe algum backup
    //caso tenha, ele copia para o buff e buff_total
    //caso não tenha, ele lê com read e passa para o buff_total
    if (save != NULL){
        ft_strlcpy(buff, save, ft_strlen(save));
        buff_total = ft_strdup(buff);
        printf("1-Buff: %s\n", buff);
        printf("1-Buff_total: %s\n", buff_total);
    }else {
        return_read = read(fd, buff, buffer_size);
        buff_total = ft_strdup(buff);
        printf("2-Buff: %s\n", buff);
        printf("2-Buff_total: %s\n", buff_total);
    }

    //no while ele verifica se existe um \n dentro de total
    //se não existir ele executa o loop lendo uma nova quantidade
    //de cacharacteres e adicionando ao buffer_total
    printf("---------------\n");
    while (linebreak(buff_total) == -1 && return_read > 0){
        return_read = read(fd, buff, buffer_size);
        printf("return_read: %d\n", return_read);
        buff_total = ft_strjoin_free1(buff_total, buff);
        printf("Buff_total: %s\n", buff_total);
    }

    //verifica a posição da quebra se linha
    index_n = linebreak(buff_total);
    //copia até a quebra
    result = malloc(sizeof(char) * index_n + 1);
    ft_strlcpy(result, buff_total, index_n + 1);
    //salva o restante no statico
    save = ft_strindexcpy(buff_total, index_n);

    //Resultados
    printf("---------------\n");
    printf("Index_n: %d\n", index_n);
    printf("Buff: %s\n", buff);
    printf("Buff_total: %s\n", buff_total);
    printf("Save: %s\n", save);
    printf("Result: %s|\n", result);

    free(buff);
    free(buff_total);
    *line = result;
    return (1);
}