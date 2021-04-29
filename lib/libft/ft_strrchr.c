/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:05:25 by famacama          #+#    #+#             */
/*   Updated: 2020/01/24 14:30:02 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	size_t j;
	size_t x;

	i = 0;
	j = 0;
	x = 0;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
		{
			j = i;
			x = 1;
		}
		i++;
	}
	if (x == 0)
		return (NULL);
	return ((char *)s + j);
}
