/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:04:11 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/02 16:19:18 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_private.h"
#include <stdlib.h>

t_list	*list_create(t_list_free_fn lsfree)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list_init(list, lsfree);
	return (list);
}

t_list_node	*list_push_front(t_list *list, void *content)
{
	t_list_node	*node;

	if (!list)
		return (NULL);
	node = node_create(content);
	if (!node)
		return (NULL);
	link_between(&list->sentinel, node, list->sentinel.next);
	list->size++;
	return (node);
}

t_list_node	*list_push_back(t_list *list, void *content)
{
	t_list_node	*node;

	if (!list)
		return (NULL);
	node = node_create(content);
	if (!node)
		return (NULL);
	link_between(list->sentinel.prev, node, &list->sentinel);
	list->size++;
	return (node);
}

void	*list_pop_front(t_list *list)
{
	t_list_node	*node;
	void		*content;

	if (!list || list->size == 0)
		return (NULL);
	node = list->sentinel.next;
	content = node->content;
	unlink_node(node);
	free(node);
	list->size--;
	return (content);
}

void	*list_pop_back(t_list *list)
{
	t_list_node	*node;
	void		*content;

	if (!list || list->size == 0)
		return (NULL);
	node = list->sentinel.prev;
	content = node->content;
	unlink_node(node);
	free(node);
	list->size--;
	return (content);
}
