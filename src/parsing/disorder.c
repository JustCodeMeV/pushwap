/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:05:37 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/05 19:41:31 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

float	get_disorder(t_list *list)
{
	t_list_node	*it;
	t_list_node	*next_it;
	int			mistakes;
	int			total_pairs;

	if (!list || list_empty(list))
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	it = list_first(list);
	while (it)
	{
		next_it = list_next(list, it);
		while (next_it)
		{
			total_pairs++;
			if (*(int *)list_content(it) > *(int *)list_content(next_it))
				mistakes++;
			next_it = list_next(list, next_it);
		}
		it = list_next(list, it);
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}
