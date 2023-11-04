/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:17:36 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/04 16:14:57 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	static int		i;
	unsigned long	nbr;

	i = 0;
	nbr = nb;
	if (nbr > 9)
	{
		ft_putunbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
		i++;
	}
	else
	{
		ft_putchar(nbr + '0');
		i++;
	}
	return (i);
}
