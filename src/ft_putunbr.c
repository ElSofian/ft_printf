/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:17:36 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/03 22:26:22 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_putunbr(unsigned int nbr)
{
	static int	i;

	i = 0;
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
