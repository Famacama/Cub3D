/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:36:46 by famacama          #+#    #+#             */
/*   Updated: 2020/11/27 20:09:26 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/milx.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_size_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[j])
		{
			if (base[j + 1] != '\0' && base[j + 1] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nb, char *base)
{
	long int nbr;

	nbr = nb;
	if (ft_size_base(base) == 0)
	{
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= ft_size_base(base))
		ft_putnbr_base((nbr / ft_size_base(base)), base);
	ft_putchar(base[nbr % ft_size_base(base)]);
}
/*
**#include <stdio.h>
**#include <stdlib.h>
**int main()
**{
**	char base[] = "poneyvif";
**	ft_putnbr_base(4565, base);
**	return(0);
**}
*/
