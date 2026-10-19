/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:38:07 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/23 14:38:09 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == NULL && dest == NULL)
		return (dest);
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			((char *) dest)[n] = ((const char *) src)[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *) dest)[i] = ((const char *) src)[i];
			i++;
		}
	}
	return (dest);
}
