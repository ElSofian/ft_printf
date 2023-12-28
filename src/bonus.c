/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 08:43:46 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/28 10:58:04 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hashtag(va_list ap, const char *format)
{
	int	i;

	i = 0;
	if (*(format + 1) == 'x')
	{
		i += ft_putstr("0x");
		i += ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef");
	}
	else if (*(format + 1) == 'X')
	{
		i += ft_putstr("0X");
		i += ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	}
	return (i);
}

int	space(va_list ap, const char *format)
{
	int	i;
	int	nbr;

	i = 0;
	if (*(format + 1) == 'd' || *(format + 1) == 'i')
	{
		nbr = va_arg(ap, int);
		if (nbr >= 0)
			i += ft_putchar(' ');
		else
			i++;
		i += ft_putnbr(nbr);
	}
	return (i);
}

int	plus(va_list ap, const char *format)
{
	int	i;
	int	nbr;

	i = 0;
	if (*(format + 1) == 'd' || *(format + 1) == 'i')
	{
		nbr = va_arg(ap, int);
		if (nbr >= 0)
			i += ft_putchar('+');
		else
			i++;
		i += ft_putnbr(nbr);
	}
	return (i);
}
