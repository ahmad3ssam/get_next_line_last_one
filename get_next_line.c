/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:16:57 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/24 18:55:43 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool has_nl(char *p)
{
	int i=0;
	while(p[i] != '\n' && p[i])
		i++;
	if(p[i] == '\n')
		return(true);
	return(false);
}
void 	new_str(char *p)
{
	int i= 0;
	int j =0;
	while(p[i] != '\n' && p[i] != '\0')
		i++;
	// if(p[i] == '\0')
	// {
	// 	p[0] = '\0';
	// 	return ;
	// }
	i++;
	//printf("i in new_str:%d %c\n",i,p[i]);
	while(p[i])
	{
		p[j] = p[i];
		i++;
		j++;
	}
	p[j] ='\0';
}

int	len_etb(char *p)
{
	int i = 0;

	while (p[i] != '\n' && p[i] != '\0')
		i++;

	if (p[i] == '\n')
		return (i + 1);
	return (i);
}


char	*cpye_to_nl(char *p)
{
	char *line;
	int len;
	int i = 0;
	len = len_etb(p);

	if(!p[0])
		return(NULL);
	line = malloc(len + 1);
	if(!line)
		return(NULL);
	while(i < len)
	{
		line[i] = p[i];
		i++;
	}

	if(p[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return(line);
}

// char  *get_line(char *p,char *ptr)
// {
// 	ptr = ft_strjoin(ptr,p);
// 	return(ptr);
// }

char	*get_next_line(int fd)
{
	char			*ptr;
	static char p[BUFFER_SIZE + 1];
	int read_f;

	if (fd <= 2 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!p[0])
		read_f = read(fd,p,BUFFER_SIZE);
	if(read_f <= 0)
		return(NULL);
	p[read_f] = '\0';
	ptr = cpye_to_nl(p);
	while(1)
	{
		if(has_nl(p))
			break;
		printf("hi2\n");
		read_f = read(fd,p,BUFFER_SIZE);
		if(read_f <= 0)
			break;
		ptr = ft_strjoin(ptr, p);
	}
	// ptr= NULL;
	new_str(p);
	printf(":%s\n",p);
	// printf("ptr in gnl:%s\n",ptr);

	return (ptr);
}



int	main(void)
{
	int i = 0;
	int fd = open("ahmad.txt", O_RDONLY);
	//#define DEFAULT_FILE_CONTAIN { .p = {0}, .fd = -1, .read_f = 0, .i = 0, .atn = false }

	// printf("%s,%d,%d,%d,%d\n",g_file.p,g_file.fd,g_file.read_f,g_file.i,g_file.atn);
	while (i < 20)
	{
		char *p = get_next_line(fd);
		printf("line %d %s",i,p);
		free(p);
		i++;
	}
	// printf("%s,%d,%d,%d,%d\n",g_file.p,g_file.fd,g_file.read_f,g_file.i,g_file.atn);

}