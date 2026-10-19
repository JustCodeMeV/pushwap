/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_query.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:04:24 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/02 16:19:18 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	list_empty(const t_list *list)
{
	if (!list)
		return (1);
	return (list->size == 0);
}

size_t	list_size(const t_list *list)
{
	if (!list)
		return (0);
	return (list->size);
}

t_list_node	*list_find(const t_list *list, const void *key, t_list_cmp_fn cmp)
{
	const t_list_node	*cur;

	if (!list || !cmp)
		return (NULL);
	cur = list->sentinel.next;
	while (cur != &list->sentinel)
	{
		if (cmp(key, cur->content) == 0)
			return ((t_list_node *)cur);
		cur = cur->next;
	}
	return (NULL);
}

void	list_foreach(t_list *list, t_list_visit_fn fn, void *ctx)
{
	t_list_node	*cur;
	t_list_node	*next;

	if (!list || !fn)
		return ;
	cur = list->sentinel.next;
	while (cur != &list->sentinel)
	{
		next = cur->next;
		fn(cur->content, ctx);
		cur = next;
	}
}

void	*list_content(const t_list_node *node)
{
	if (!node)
		return (NULL);
	return (node->content);
}
