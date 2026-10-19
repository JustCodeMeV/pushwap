/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:04:38 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/02 16:04:39 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_private.h"
#include <stdlib.h>

void	list_destroy(t_list *list)
{
	if (!list)
		return ;
	list_clear(list);
	free(list);
}

void	list_clear(t_list *list)
{
	t_list_node	*cur;
	t_list_node	*next;

	if (!list)
		return ;
	cur = list->sentinel.next;
	while (cur != &list->sentinel)
	{
		next = cur->next;
		if (list->lsfree && cur->content)
			list->lsfree(cur->content);
		free(cur);
		cur = next;
	}
	list_init(list, list->lsfree);
}

void	list_rotate_cw(t_list *list)
{
	t_list_node	*last;

	if (!list || list->size < 2)
		return ;
	last = list->sentinel.prev;
	unlink_node(last);
	link_between(&list->sentinel, last, list->sentinel.next);
}

void	list_rotate_ccw(t_list *list)
{
	t_list_node	*first;

	if (!list || list->size < 2)
		return ;
	first = list->sentinel.next;
	unlink_node(first);
	link_between(list->sentinel.prev, first, &list->sentinel);
}
