/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 13:37:43 by famacama          #+#    #+#             */
/*   Updated: 2020/11/25 12:03:20 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../../lib/libft/libft.h"

int		get_next_line(int fd, char **line);
int		read_file(int fd, char **rest, char **line);
int		dispatch_str(char **rest, char **line, int tot_read);
size_t	ft_strlen_g(char *s);
int		ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strsub(char *s, int start, size_t len);
char	*ft_strnew(char *str);

#endif
