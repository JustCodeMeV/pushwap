/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 16:07:37 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/14 16:55:14 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	base_length(char *base)
{
	int	length;

	length = 0;
	while (base[length])
		length++;
	return (length);
}

int	ft_putptr_base(unsigned long n, char *base)
{
	int	blen;
	int	count;

	blen = base_length(base);
	count = 0;
	if (n >= (unsigned long)blen)
		count += ft_putptr_base(n / blen, base);
	ft_putchar_count(base[n % blen]);
	return (count + 1);
}
