/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:13:41 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/04 16:05:01 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putaddr(void *addr)
{
	int					i;
	int					len;
	char				*base;
	unsigned long long	address;

	len = 0;
	len += ft_putstr("0x");
	i = sizeof(void *) + 3;
	base = "0123456789abcdef";
	address = (unsigned long long) addr;
	while (i >= 0)
	{
		ft_putchar(base[(address >> (i * 4)) & 0xF]);
		len++;
		i--;
	}
	return (len);
}
