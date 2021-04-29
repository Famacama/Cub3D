/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:05:55 by famacama          #+#    #+#             */
/*   Updated: 2020/02/03 11:52:49 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_tab(int n)
{
	int				l;
	unsigned int	nb;

	l = 1;
	if (n < 0)
	{
		nb = -n;
		l++;
	}
	else
		nb = n;
	while (nb > 9)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

static char	*less_than_then(int nb, char *tab, int i)
{
	tab[i++] = nb + 48;
	tab[i] = '\0';
	return (tab);
}

static char	*full_tab(int n, char *tab, long nb, int l)
{
	int i;
	int d;

	i = 0;
	d = 1;
	while (l-- > 0)
	{
		if (n < 0)
		{
			tab[i++] = '-';
			l--;
			n = 0;
		}
		d *= 10;
	}
	if ((nb > 0) && (nb < 10))
		return (less_than_then(nb, tab, i));
	while (d > 0)
	{
		tab[i++] = nb / d + 48;
		nb = nb % d;
		d = d / 10;
	}
	tab[i] = '\0';
	return (tab);
}

char		*ft_itoa(int n)
{
	int		l;
	char	*tab;
	long	nb;
	int		i;

	i = 0;
	l = ft_size_tab(n) - 1;
	nb = (n < 0) ? -n : n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(tab = malloc(sizeof(char) * (l + 2))))
		return (NULL);
	tab[i--] = '\0';
	if (n == 0 && (tab[0] = '0'))
		return (tab);
	return (full_tab(n, tab, nb, l));
}
