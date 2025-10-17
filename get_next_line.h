/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:19:11 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/24 17:19:12 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42
#endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

// char	*get_next_line(int fd);
// int	len_etb(char *p);
// char	*ft_strjoin(char *s1, char *s2);
// int	ft_strlen(char *s);
// // char *get_line(char *p,char *ptr);
// void	ft_strlcpy(char *dest, const char *src);
// char	*cype_to_nl(char *p);
// void	ft_strlcat(char *dst, char *src);
// // void 	new_str(char *p);


char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *s);
void	ft_strlcpy(char *dest, const char *src);
void	ft_strlcat(char *dst, char *src);
char	*get_next_line(int fd);
int	len_etb(char *p);
char	*cpye_to_nl(char *p);
bool has_nl(char *p);









#endif