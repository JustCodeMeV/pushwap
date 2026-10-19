/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:04:41 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/02 16:04:42 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_private.h"
#include <stdlib.h>

t_list_node	*list_insert_before(t_list *list, t_list_node *pos, void *content)
{
	t_list_node	*node;

	if (!list)
		return (NULL);
	if (!pos || pos == &list->sentinel)
		return (list_push_back(list, content));
	node = node_create(content);
	if (!node)
		return (NULL);
	link_between(pos->prev, node, pos);
	list->size++;
	return (node);
}

t_list_node	*list_insert_after(t_list *list, t_list_node *pos, void *content)
{
	t_list_node	*node;

	if (!list)
		return (NULL);
	if (!pos || pos == &list->sentinel)
		return (list_push_front(list, content));
	node = node_create(content);
	if (!node)
		return (NULL);
	link_between(pos, node, pos->next);
	list->size++;
	return (node);
}

void	list_erase(t_list *list, t_list_node *node)
{
	if (!list || !node || node == &list->sentinel)
		return ;
	unlink_node(node);
	if (list->lsfree && node->content)
		list->lsfree(node->content);
	free(node);
	list->size--;
}

void	*list_remove_node(t_list *list, t_list_node *node)
{
	void	*content;

	if (!list || !node || node == &list->sentinel)
		return (NULL);
	content = node->content;
	unlink_node(node);
	free(node);
	list->size--;
	return (content);
}
