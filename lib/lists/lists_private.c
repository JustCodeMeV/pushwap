/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_private.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:04:33 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/02 16:19:18 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_private.h"
#include <stdlib.h>

void	list_init(t_list *list, t_list_free_fn lsfree)
{
	list->sentinel.next = &list->sentinel;
	list->sentinel.prev = &list->sentinel;
	list->sentinel.content = NULL;
	list->size = 0;
	list->lsfree = lsfree;
}

t_list_node	*node_create(void *content)
{
	t_list_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->content = content;
	return (node);
}

void	link_between(t_list_node *left, t_list_node *node, t_list_node *right)
{
	node->prev = left;
	node->next = right;
	left->next = node;
	right->prev = node;
}

void	unlink_node(t_list_node *node)
{
	t_list_node	*left;
	t_list_node	*right;

	left = node->prev;
	right = node->next;
	left->next = right;
	right->prev = left;
	node->prev = NULL;
	node->next = NULL;
}
