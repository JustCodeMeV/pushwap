/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:11:07 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/24 14:11:21 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat_fd(float n, int fd)
{
	int	scaled;

	scaled = (int)(n * 100.0f + 0.5f);
	if (scaled < 0)
	{
		ft_putchar_fd('-', fd);
		scaled = -scaled;
	}
	ft_putnbr_fd(scaled / 100, fd);
	ft_putchar_fd('.', fd);
	ft_putchar_fd((scaled / 10) % 10 + '0', fd);
	ft_putchar_fd(scaled % 10 + '0', fd);
}
