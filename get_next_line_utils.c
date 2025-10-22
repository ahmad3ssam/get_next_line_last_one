/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:42:55 by ahhammad          #+#    #+#             */
/*   Updated: 2025/10/22 15:42:55 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strlcat(char *dst, char *src)
{
	int		i;
	int		len_dest;

	i = 0;
	len_dest = ft_strlen(dst);
	while (src[i] != '\n' && src[i] != '\0')
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dst[len_dest + i] = '\n';
		i++;
	}
	dst[len_dest + i] = '\0';
}

void	ft_strlcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_strlen(char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		len;
	char		*str;
	int			len_src;

	if (s1 && !s2[0])
		return (s1);
	len_src = len_etb(s2);
	len = ft_strlen(s1) + len_src + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1);
	free(s1);
	ft_strlcat(str, s2);
	return (str);
}
