#include <stdio.h>
#include <stdlib.h>
int	len_etb(char *p)
{
	int i = 0;

	while (p[i] != '\n' && p[i] != '\0')
		i++;

	if (p[i] == '\n')
		return (i + 1);
	return (i);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
void	ft_strlcat(char *dst, char *src)
{
	int i;
	int len_dest;

	i = 0;
	len_dest = ft_strlen(dst);
	while (src[i] != '\n' && src[i] != '\0')
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	if(src[i] == '\n')
	{
		dst[len_dest + i] = '\n';
		i++;
	}
	dst[len_dest + i] = '\0';
}


void	ft_strlcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i]='\0';
}



char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	int len_src;

	if (s1 && !s2[0])
		return (s1);
	len_src = len_etb(s2);
	len = ft_strlen(s1) + len_src + 1;
	str = malloc(len);
    printf("hi\n");
	if (!str)
		return (NULL);
    printf("hi\n");
    
	ft_strlcpy(str, s1);
    printf("hi\n");
	free(s1);
    printf("hi\n");
	ft_strlcat(str, s2);
    printf("hi\n");
	return (str);
}


int main()
{

    static char p[12];
    
    char *s =malloc(12);
    s[0]= '6';
    s[1]= '4';
    s[2]= '5';

    s= ft_strjoin(s,p); 
    printf("%s",s);
}