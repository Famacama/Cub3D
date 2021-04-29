/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:54:00 by marvin            #+#    #+#             */
/*   Updated: 2020/01/13 12:36:22 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	i = n;
	if (src == 0 && dst == 0)
		return (0);
	if (tmp_dst > tmp_src && tmp_dst < (tmp_src + n))
		while (n > 0)
		{
			tmp_dst[n - 1] = tmp_src[n - 1];
			n--;
		}
	else
	{
		i = -1;
		while (++i < n)
			tmp_dst[i] = tmp_src[i];
	}
	return (dst);
}
