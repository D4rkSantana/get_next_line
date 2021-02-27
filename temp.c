#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

    /**
     * Devolve o tamanho da string recebida
     * 
     * Retorna no padrão 0 - 10 
    **/
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int  linebreak(char * str){
    int     count;

    /**
     * Esse programa retorna o index de onde esta o \n
     * com o padrão de 0 - 10
     * 
     * caso não exista um \n ele retorna -1
    **/
    count = 0;
    while (str[count])
    {
        if(str[count] == '\n')
            return (count);
        count++;
    }
    return (-1);
}

static void	ft_bzero(char *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	str = malloc(count * size);
	if (str == 0)
		return (0);
	ft_bzero(str, (count * size));
	return (str);
}

static size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	len;

    /**
     * Recebe um destino, um conteudo e o tamanho
     * 
     * utiliza padrão 0 - 10
    **/

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

static char *ft_strindexcpy(char **save, char * str, size_t index){
	size_t  count;
	char    *dst;

    /**
     * Semelhante ao ft_strncpy, porem copia a partir
     * da posição indicada e aloca espaço.
     * 
     * recebe o index no padrão 1 - 10
     * 
     * retorna o ponteiro da string que recebeu o conteudo
    **/
	count = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) - index));
	while (count < ft_strlen(str) && index < ft_strlen(str)){
	    dst[count] = str[index];
	    index++;
	    count++;
	}
    dst[count] = '\0';
    if (save != NULL)
        free(save);
    *save = dst;
	return (dst);
}

int main(){
    char *d;
    int size;
    int i;

    i = 0;
    size = 32;
    d = (char *)malloc(sizeof(char) * size + 1);
    printf("\nft_strlen d: %ld\n", ft_strlen(d));
    ft_strlcpy(d, "01234567890123456789012345678901", size + 1);
    printf("\nstr: %s\n", d);
    printf("\nft_strlen: %ld\n", ft_strlen(d));
    while (d[i])
    {
        d[i] = '\0';
        i++;
    }
    printf("\nstr: %s\n", d);
    printf("\nft_strlen: %ld\n", ft_strlen(d));
    return (0);
}