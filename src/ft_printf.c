/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:23:37 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/03 21:00:50 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	put_hex(unsigned int nb, char *base)
{
	if (nb > 15)
	{
		put_hex(nb / ft_strlen(base), base);
		ft_putchar(base[nb % ft_strlen(base)]);
	}
	else
		ft_putchar(base[nb]);
}

void	print_var(va_list ap, const char *format)
{
	char	*base;
	
	base = "0123456789abcdef";
	if (*format == 'c')
		ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		ft_putstr(va_arg(ap, char *));
	else if (*format == 'p')
		put_hex(va_arg(ap, unsigned int), base);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (*format == 'u')
		ft_putnbr(va_arg(ap, unsigned int));
	else if (*format == 'x')
		put_hex((int)va_arg(ap, unsigned int), base);
	else if (*format == 'X')
	{
		base = "0123456789ABCDEF";
		put_hex((int)va_arg(ap, unsigned int), base);
	}
	else if (*format == '%')
		ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	ap;

	i = 0;
	va_start(ap, *format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 's' || *format == 'p'
				|| *format == 'd' || *format == 'i' || *format == 'u'
				|| *format == 'x' || *format == 'X' || *format == '%')
				print_var(ap, format);
			else
				return (-1);
		}
		else
			ft_putchar(*format);
		format++;
		i++;
	}
	va_end(ap);
	return (i);
}

int	main(void)
{
	char	c;
	int	i;
	
	c = 'S';	
	i = ft_printf("Hello World\nMy name is %s, I'm a studentat %d Paris.\nThe first letter of my first name is %p\nThere is a pourcentage character: %%.\n", "Sofian", 42, &c);
	ft_printf("Return value : %d\n", i);
	return (0);
}