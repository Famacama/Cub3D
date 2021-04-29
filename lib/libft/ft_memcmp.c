/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:08:40 by marvin            #+#    #+#             */
/*   Updated: 2020/01/20 15:04:57 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*t;

	i = -1;
	s = (unsigned char *)s1;
	t = (unsigned char *)s2;
	while (++i < n)
		if (s[i] != t[i])
			return (s[i] - t[i]);
	return (0);
}
