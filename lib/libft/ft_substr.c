/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:43:04 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/23 14:43:07 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (!s || *s == 0)
		return (ft_strdup(""));
	size = ft_strlen(s);
	if (start > size || !len)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	sub = ft_calloc(len * sizeof(char) + 1, 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
