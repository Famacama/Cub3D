/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:31:44 by marvin            #+#    #+#             */
/*   Updated: 2020/01/24 14:29:08 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*src;
	size_t		i;

	src = (const char *)s;
	i = -1;
	while (++i < n)
		if (src[i] == c)
			return ((void *)&src[i]);
	return (NULL);
}
