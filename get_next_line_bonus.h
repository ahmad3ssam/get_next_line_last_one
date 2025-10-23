/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bouns.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:09:12 by ahhammad          #+#    #+#             */
/*   Updated: 2025/10/23 14:09:12 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strlcpy(char *dest, const char *src);
void	ft_strlcat(char *dst, char *src);
char	*get_next_line(int fd);
char	*cpye_to_nl(char *p);
bool	has_nl(char *p);
int		len_etb(char *p);
#endif
