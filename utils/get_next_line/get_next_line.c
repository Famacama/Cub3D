/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 07:14:04 by famacama          #+#    #+#             */
/*   Updated: 2020/11/25 11:56:20 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	dispatch_str(char **rest, char **line, int tot_read)
{
	char	*tempo;

	if (*rest[0] == '\n')
	{
		*line = ft_strsub(*rest, 0, 0);
		tempo = *rest;
		*rest = ft_strsub(*rest, 1, (ft_strlen_g(*rest)));
		free(tempo);
		if (*line == NULL || *rest == NULL)
			return (-1);
		return (1);
	}
	*line = ft_strsub(*rest, 0, (tot_read));
	tempo = *rest;
	*rest = ft_strsub(*rest, (tot_read + 1), ((ft_strlen_g(*rest) - tot_read)));
	free(tempo);
	if (*line == NULL || *rest == NULL)
		return (-1);
	return (1);
}

int	read_file(int fd, char **rest, char **line)
{
	char	*tempo;
	int		tot_read;
	char	buf[BUFFER_SIZE + 1];

	if (read(fd, buf, 0))
		return (-1);
	if (!(*rest))
		*rest = ft_strnew(*rest);
	while ((tot_read = read(fd, buf, (BUFFER_SIZE))))
	{
		buf[tot_read] = '\0';
		tempo = *rest;
		*rest = ft_strjoin_gnl(*rest, buf);
		free(tempo);
		if ((tot_read = ft_strchr_gnl(*rest, '\n')))
			return (dispatch_str(&*rest, line, tot_read));
	}
	if (*rest)
		*line = ft_strsub(*rest, 0, ft_strlen_g(*rest));
	free(*rest);
	*rest = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX];
	int			tot_read;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	if (rest[fd])
		if ((tot_read = ft_strchr_gnl(rest[fd], '\n')))
			return (dispatch_str(&rest[fd], line, tot_read));
	return (read_file(fd, &rest[fd], line));
}
