/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:42:51 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/23 14:42:56 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;
	size_t	i;

	if (!set)
		return (ft_strdup(s1));
	if (!s1 || *s1 == 0)
		return (ft_strdup(""));
	i = 0;
	head = 0;
	tail = 0;
	while (ft_strchr(set, s1[i++]))
		head++;
	while (ft_strrchr(set, s1[ft_strlen(s1) - 1 - tail]))
		tail++;
	return (ft_substr(s1, head, ft_strlen(s1) - tail - head));
}
