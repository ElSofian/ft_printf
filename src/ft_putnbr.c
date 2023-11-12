/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:19:24 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/12 15:35:41 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	nbrlength(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

int	ft_putnbr(int nb)
{
	long		nbr;

	nbr = nb;
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + 48);
	}
	else
		ft_putchar(nbr + 48);
	return (nbrlength(nb));
}
