#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlen(const char *s);

int ft_strindexcpy(char * dst, const char * str, size_t index);

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
    char    *save;
    int     x;
    int     i;
    int     aux;

    //=========================================
    //Alocação do buff e leitura
    //=========================================
    x = 32;
    buff = malloc(sizeof(char) * x);
    resultado = read(fd, buff, x);
    printf("Retorno read: %ld\n------------", resultado);
    //=========================================
    //Pesquisa da posição da primeira quebra de linha
    //=========================================
    i = linebreak(buff);
    printf("\nRetorno do linebreak: %d", i);
    aux = ft_strindexcpy(save, buff, i);
    printf("\nRetorno do strindexcpy: %d", aux);
    printf("\nSave: %s\n------------\n", save);
    //=========================================
    //Alocação da memoria para o buff de linha e copia
    //=========================================
    buff_line = malloc(sizeof(char) * i);
    ft_strlcpy(buff_line, buff, i + 1);//ssss
    //=========================================
    //Apresentação dos valores
    //=========================================
    i = ft_strlen(buff);
    printf("\nStrlen do buff: %d", i);
    i = ft_strlen(buff_line);
    printf("\nStrlen do buff_line: %d", i);
    i = ft_strlen(save);
    printf("\nStrlen do save: %d\n------------", i);
    printf("\nBuff: %s", buff);
    printf("\nBuff_line: %s", buff_line);
    printf("\nSave: %s\n------------\n", save);
    //=========================================
    //Finalização
    //=========================================
    free (buff);
    free(buff_line);
    return (resultado);
}
int ft_strindexcpy(char * dst, const char * str, size_t index){
	int count;
	int size;

	count = 0;
	if (str == NULL)
	    return (-1);
	dst = malloc(sizeof(char) * (ft_strlen(str) - index) + 1);
	while (count < ft_strlen(str) && index < ft_strlen(str)){
	    dst[count] = str[index];
        //printf("\ndst: %c = str: %c", dst[count], str[index]);
	    index++;
	    count++;
	}
    dst[count] = '\0';
    //printf("\nDST: %s", dst);
	return (count);
}
int main(){
    int fd;

    //printf("==Teste==\n");
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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
