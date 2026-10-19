/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:08:22 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/10 22:11:21 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "ft_printf.h"

static int	format_pointer(va_list args)
{
	void	*pointer;

	pointer = va_arg(args, void *);
	if (!pointer)
		return (ft_putstr_count("(nil)"));
	return (ft_putstr_count("0x")
		+ ft_putptr_base((unsigned long)(uintptr_t)pointer,
		"0123456789abcdef"));
}

static int	format(char conversion, va_list args)
{
	if (conversion == 'c')
		return (ft_putchar_count(va_arg(args, int)));
	if (conversion == '%')
		return (ft_putchar_count('%'));
	if (conversion == 'p')
		return (format_pointer(args));
	if (conversion == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	if (conversion == 'd' || conversion == 'i')
		return (ft_putnbr_count(va_arg(args, int)));
	if (conversion == 'u')
		return (ft_putunbr_count(va_arg(args, unsigned int)));
	if (conversion == 'x')
		return (ft_putptr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (conversion == 'X')
		return (ft_putptr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		printed;

	if (!s || *s == 0)
		return (0);
	va_start(args, s);
	i = 0;
	printed = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			printed += format(s[i + 1], args);
			i += 2;
		}
		else
		{
			printed += ft_putchar_count(s[i]);
			i++;
		}
	}
	va_end(args);
	return (printed);
}
