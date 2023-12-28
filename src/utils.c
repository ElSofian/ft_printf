/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:48:11 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/28 10:56:37 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		ft_printf("Argument s is NULL in ft_putstr() function.\n");
		return (-1);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int nb, char *base)
{
	static int	i;

	i = 0;
	if (nb > 15)
	{
		ft_puthex(nb / 16, base);
		ft_putchar(base[nb % 16]);
		i++;
	}
	else
	{
		ft_putchar(base[nb]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		count;
	long	nbr;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putchar(nbr % 10 + 48);
	}
	else
		count += ft_putchar(nbr + 48);
	return (count);
}

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

int	ft_putaddr(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n < 16)
		count += ft_putchar(base[n]);
	else
	{
		count += ft_putaddr(n / 16);
		count += ft_putaddr(n % 16);
	}
	return (count);
}