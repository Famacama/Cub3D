/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:13:12 by famacama          #+#    #+#             */
/*   Updated: 2020/11/25 11:57:15 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		ft_strchr_gnl(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	if (s[0] == '\n')
		return (1);
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(tab = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strsub(char *s, int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strnew(char *str)
{
	if (!(str = malloc((sizeof(char) * 1))))
		return (NULL);
	str[0] = '\0';
	return (str);
}
