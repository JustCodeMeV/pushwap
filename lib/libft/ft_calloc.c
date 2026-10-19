/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:24:51 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/23 14:24:54 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated;
	size_t	divider;

	allocated = NULL;
	divider = size * nmemb;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else if (divider / nmemb != size)
		return (allocated);
	else
	{
		allocated = malloc(nmemb * size);
		if (!allocated)
			return (NULL);
		ft_bzero(allocated, nmemb * size);
		return (allocated);
	}
}
