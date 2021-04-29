/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:58:59 by famacama          #+#    #+#             */
/*   Updated: 2020/01/24 14:29:28 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != c && s[i])
		i++;
	if (s[i] == '\0')
		return (NULL);
	return ((char *)s + i);
}
