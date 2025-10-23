/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bouns.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:09:25 by ahhammad          #+#    #+#             */
/*   Updated: 2025/10/23 14:09:25 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	has_nl(char *p)
{
	int		i;

	i = 0;
	while (p[i] != '\n' && p[i])
		i++;
	if (p[i] == '\n')
		return (true);
	return (false);
}

void	new_str(char *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (p[i] != '\n' && p[i] != '\0')
		i++;
	i++;
	while (p[i])
	{
		p[j] = p[i];
		i++;
		j++;
	}
	p[j] = '\0';
}

int	len_etb(char *p)
{
	int		i;

	i = 0;
	while (p[i] != '\n' && p[i] != '\0')
		i++;
	if (p[i] == '\n')
		return (i + 1);
	return (i);
}

char	*cpye_to_nl(char *p)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = len_etb(p);
	if (!p[0])
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = p[i];
		i++;
	}
	if (p[i] == '\n' && p[i - 1] != '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		p[1024][BUFFER_SIZE + 1];
	char			*ptr;
	int		read_f;

	read_f = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!p[fd][0])
		read_f = read(fd, p[fd], BUFFER_SIZE);
	p[fd][read_f] = '\0';
	ptr = cpye_to_nl(p[fd]);
	while (ptr != NULL)
	{
		if (has_nl(p[fd]))
			break ;
		read_f = read(fd, p[fd], BUFFER_SIZE);
		p[fd][read_f] = '\0';
		if (read_f <= 0)
			break ;
		ptr = ft_strjoin(ptr, p[fd]);
	}
	new_str(p[fd]);
	return (ptr);
}
