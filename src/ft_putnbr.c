/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:19:24 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/03 22:03:51 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_putnbr(int nb)
{
	long		nbr;
	static int	i;

	nbr = nb;
	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
		i++;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + 48);
		i++;
	}
	else
	{
		ft_putchar(nbr + 48);
		i++;
	}
	return (i);
}
