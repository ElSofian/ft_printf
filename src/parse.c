/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 08:39:20 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/28 10:58:19 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_hashtag(const char *format)
{
	if (*(format + 1) != 'x' && *(format + 1) != 'X')
		return (-1);
	return (1);
}

static int	parse_space(const char *format)
{
	if (*(format + 1) != 'd' && *(format + 1) != 'i')
		return (-1);
	return (1);
}

static int	parse_plus(const char *format)
{
	if (*(format + 1) != 'd' && *(format + 1) != 'i')
		return (-1);
	return (1);
}

int	parse(const char *format)
{
	int	i;

	i = 0;
	if (*format == '#')
		i = parse_hashtag(format);
	else if (*format == ' ')
		i = parse_space(format);
	else if (*format == '+')
		i = parse_plus(format);
	if (i < 0)
		ft_putstr("%(INVALID_FORMAT)");
	return (i);
}
