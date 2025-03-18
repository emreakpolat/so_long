/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:01:25 by makpolat          #+#    #+#             */
/*   Updated: 2024/11/27 11:58:59 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char c, va_list args, int a)
{
	if (c == 'c')
		a += ft_putchar(va_arg(args, int));
	else if (c == 's')
		a += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		a += convert_pointer(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		a += ft_putnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		a += converthexa(va_arg(args, unsigned long), c);
	else if (c == 'u')
		a += ft_putnbr(va_arg(args, unsigned int));
	else if (c == '%')
		a += ft_putchar(c);
	return (a);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		number;

	number = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			number = ft_check(format[++i], args, number);
			i++;
		}
		else
		{
			number += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (number);
}
