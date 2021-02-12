#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

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
            return (count);
        count++;
    }
    return(-1);
}
static size_t leitor(int fd){
    size_t  resultado;
    char    *buff;
    char    *buff_line;
    int     x;
    int     i;

    //=========================================
    //Alocação do buff e leitura
    //=========================================
    x = 32;
    buff = malloc(sizeof(char) * x);
    resultado = read(fd, buff, x);
    printf("==Resultado: %ld ==\n", resultado);
    //=========================================
    //Pesquisa da posição da primeira quebra de linha
    //=========================================
    i = linebreak(buff);
    printf("\n==Retorno: %d ==", i);
    //=========================================
    //Alocação da memoria para o buff de linha e copia
    //=========================================
    buff_line = malloc(sizeof(char) * i);
    ft_strlcpy(buff_line, buff, i + 1);
    //=========================================
    //Apresentação dos valores
    //=========================================
    printf("\nBuff: %s", buff);
    printf("\nBuff_line: %s", buff_line);
    printf("\n==Fim do programa==\n");
    //=========================================
    //Finalização
    //=========================================
    free (buff);
    free(buff_line);
    return (resultado);
}
int main(){
    int fd;

    printf("==Teste==\n");
    fd = open("texto.txt", O_RDONLY);
    leitor(fd);
    close(fd);
    return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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