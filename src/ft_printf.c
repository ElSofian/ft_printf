/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:23:37 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/04 16:14:06 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	put_hex(unsigned int nb, char *base)
{
	static int	i;

	i = 0;
	if (nb > 15)
	{
		put_hex(nb / ft_strlen(base), base);
		ft_putchar(base[nb % ft_strlen(base)]);
		i++;
	}
	else
	{
		ft_putchar(base[nb]);
		i++;
	}
	return (i);
}

int	print_var(va_list ap, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		i += ft_putaddr(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		i += ft_putunbr(va_arg(ap, unsigned int));
	else if (format == 'x')
		i += put_hex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		i += put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		i += ft_putchar('%');
	else
	{
		i += ft_putchar('%');
		i += ft_putchar(format);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	if (!format)
		return (-1);
	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i += print_var(ap, *format);
		}
		else
			i += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (i);
}

// int	main(void)
// {
// 	int		i;
// 	char	c;

// 	c = 'c';
// 	i = ft_printf("Hello World\nMy name is %s, I'm a student at %x Paris.
// 	\nThe first letter of my first name is %p
// 	\nThere is a pourcentage character: %%.\n", "Sofian", 1000, &c);
// 	ft_printf("Return value : %d\n", i);
// 	printf("\n-----------------------\n");
// 	i = printf("Hello World\nMy name is %s, I'm a student at %x Paris.
// 	\nThe first letter of my first name is %p
// 	\nThere is a pourcentage character: %%.\n", "Sofian", 1000, &c);
// 	printf("Return value : %d\n", i);
// 	return (0);
// }