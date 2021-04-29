/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:13 by famacama          #+#    #+#             */
/*   Updated: 2020/01/24 14:13:45 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t l;
	size_t j;

	i = 0;
	l = 0;
	j = 0;
	while (src[l])
		l++;
	while (dest[i])
		i++;
	if (size <= i)
		l = l + size;
	else
		l = l + i;
	while (i + 1 < size && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (l);
}
