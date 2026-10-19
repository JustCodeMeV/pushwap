/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 22:06:00 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/14 16:02:47 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_count(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_count(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr_count("(null)"));
	i = 0;
	while (s[i])
	{
		ft_putchar_count(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_count(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_count('-');
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr_count(n / 10);
	ft_putchar_count((n % 10) + '0');
	return (count + 1);
}

int	ft_putunbr_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr_count(n / 10);
	ft_putchar_count((n % 10) + '0');
	return (count + 1);
}
