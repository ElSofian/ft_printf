/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:19:52 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/13 17:08:08 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
// A enlever hors correction
# include <stdio.h>
// -------------------------

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_puthex(unsigned int nb, char *base);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_putaddr(unsigned long n);

int	hashtag(va_list ap, const char *format);
int	space(va_list ap, const char *format);
int	plus(va_list ap, const char *format);
int	parse(const char *format);
int	ft_printf(const char *format, ...);

#endif