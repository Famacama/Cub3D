/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:34:28 by famacama          #+#    #+#             */
/*   Updated: 2020/01/24 14:29:56 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t slen)
{
	size_t l;
	size_t b;

	if (!ft_strlen(src))
		return ((char *)dst);
	b = 0;
	while (dst[b] && b < slen)
	{
		l = 0;
		while (src[l] && dst[b + l] && src[l] == dst[b + l]
			&& (b + l) < slen)
			l++;
		if (!src[l])
			return ((char*)&dst[b]);
		b++;
	}
	return (0);
}
