/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_traverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:04:16 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/02 16:04:17 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list_node	*list_first(const t_list *list)
{
	if (!list || list->size == 0)
		return (NULL);
	return (list->sentinel.next);
}

t_list_node	*list_last(const t_list *list)
{
	if (!list || list->size == 0)
		return (NULL);
	return (list->sentinel.prev);
}

t_list_node	*list_next(const t_list *list, const t_list_node *node)
{
	const t_list_node	*next;

	if (!list || !node || node == &list->sentinel)
		return (NULL);
	next = node->next;
	if (next == &list->sentinel)
		return (NULL);
	return ((t_list_node *)next);
}

t_list_node	*list_prev(const t_list *list, const t_list_node *node)
{
	const t_list_node	*prev;

	if (!list || !node || node == &list->sentinel)
		return (NULL);
	prev = node->prev;
	if (prev == &list->sentinel)
		return (NULL);
	return ((t_list_node *)prev);
}
