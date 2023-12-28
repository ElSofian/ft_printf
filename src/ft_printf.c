/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:23:37 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/13 17:07:33 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	bonus(va_list ap, const char **format, int *i, bool *is_bonus)
{
	if (parse(*format) < 0)
	{
		*is_bonus = true;
		return (-1);
	}
	if (**format == '#')
		(*i) += hashtag(ap, *format);
	else if (**format == ' ')
		(*i) += space(ap, *format);
	else if (**format == '+')
		(*i) += plus(ap, *format);
	if (**format == '#' || **format == ' ' || **format == '+')
	{
		*is_bonus = true;
		++(*format);
	}
	return (*i);
}

static int	print_var(va_list ap, const char *format, bool *is_bonus)
{
	int	i;

	i = 0;
	if (bonus(ap, &format, &i, is_bonus) == 0)
	{
		if (*format == 'c')
			i += ft_putchar(va_arg(ap, int));
		else if (*format == 's')
			i += ft_putstr(va_arg(ap, char *));
		else if (*format == 'p')
			i += ft_putaddr(va_arg(ap, unsigned long));
		else if (*format == 'd' || *format == 'i')
			i += ft_putnbr(va_arg(ap, int));
		else if (*format == 'u')
			i += ft_putunbr(va_arg(ap, unsigned int));
		else if (*format == 'x')
			i += ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef");
		else if (*format == 'X')
			i += ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF");
		else if (*format == '%')
			i += ft_putchar('%');
		else
			i += ft_putstr("%(INVALID_FLAG)");
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	bool	is_bonus;
	va_list	ap;

	if (!format)
		return (-1);
	i = 0;
	is_bonus = false;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i += print_var(ap, format, &is_bonus);
			if (is_bonus)
				format++;
		}
		else
			i += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (i);
}

int	main(void)
{
	int		i;

	i = ft_printf("% d", +547);
	ft_printf("\nReturn value : %d\n", i);
	ft_printf("\n-----------------------\n");
	i = printf("% d", +547);
	printf("\nReturn value : %d\n", i);
	return (0);
}
