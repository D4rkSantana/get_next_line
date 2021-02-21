#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

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

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (dst[i] != '\0' && i < (dstsize - 1))
		i++;
	while (src[j] && i + j + 1 < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dstlen + srclen);
}

char				*ft_strjoin_free1(char *s1, char const *s2, size_t sz2){
	unsigned int	size;
	unsigned int	size1;
	unsigned int	size2;
	char			*new;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (sz2 > 0)
		size2 = sz2;
	size = size1 + size2 + 1;
	if (!(new = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strlcpy(new, s1, size1 + 1);
	ft_strlcat(new + size1, s2, size2 + 1);
	free(s1);
	return (new);
}

char		*ft_strdup(const char *s1)
{
	char	*dest;
	int		x;
	int		size;

	while (s1[size])
		size++;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!(dest))
		return (NULL);
	x = 0;
	while (s1[x])
	{
		dest[x] = s1[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}