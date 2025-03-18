/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:25:51 by makpolat          #+#    #+#             */
/*   Updated: 2024/11/27 11:54:44 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	converthexa(unsigned int n, char c)
{
	int		i;
	char	*a1;
	char	*a2;
	int		size;

	size = 0;
	a1 = "0123456789abcdef";
	a2 = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
		size = converthexa(n / 16, c);
	i = (n % 16);
	if (c == 'x')
		size += ft_putchar(a1[i]);
	else if (c == 'X')
		size += ft_putchar(a2[i]);
	return (size);
}

int	convert_pointer(unsigned long n)
{
	long	remainder;
	char	*alp;
	int		size;

	size = 2;
	alp = "0123456789abcdef";
	remainder = 0;
	if (n == 0)
	{
		size = ft_putstr("(nil)");
		return (size);
	}
	if (n >= 16)
		size = convert_pointer(n / 16);
	if (size == 2)
		ft_putstr("0x");
	remainder = (n % 16);
	size += ft_putchar(alp[remainder]);
	return (size);
}

int	ft_putnbr(long n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size += ft_putchar('-');
		n = -n;
		size += ft_putnbr(n);
	}
	else if (n >= 10)
	{
		size += ft_putnbr(n / 10);
		size += ft_putnbr(n % 10);
	}
	else
		size += ft_putchar(n + '0');
	return (size);
}
