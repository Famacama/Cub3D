/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:51:27 by famacama          #+#    #+#             */
/*   Updated: 2020/01/24 14:36:16 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_first(char const *s1, char const *set, int i)
{
	int j;

	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
			return (1);
		j++;
	}
	return (0);
}

static int	check_last(char const *s1, char const *set, int i)
{
	int j;

	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
			return (1);
		j++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		f;
	int		l;
	int		i;
	char	*tab;

	f = 0;
	l = 0;
	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (check_first(s1, set, i++))
		f++;
	i = ft_strlen(s1) - 1;
	while (check_last(s1, set, i--))
		l++;
	i = ft_strlen(s1);
	if ((i - f - l) < 0)
		return (ft_calloc(1, 2));
	return (tab = ft_substr(s1, f, (i - f - l)));
}
