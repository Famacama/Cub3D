/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:26:26 by famacama          #+#    #+#             */
/*   Updated: 2020/02/03 11:36:59 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (((start + len) > ft_strlen(s)) && start < ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	if (!(tab = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[start] && len != 0)
	{
		tab[i] = s[start];
		start++;
		i++;
		len--;
	}
	tab[i] = '\0';
	return (tab);
}
