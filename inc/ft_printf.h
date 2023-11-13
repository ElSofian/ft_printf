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
// A enlever hors correction
// # include <stdio.h>
// -------------------------

int		print_var(va_list ap, const char format);
int		put_hex(unsigned int nb, char *base);
int		ft_strlen(const char *str);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int nb);
int		ft_putaddr(void *addr);
int		ft_printf(const char *format, ...);

#endif