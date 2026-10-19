/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:04:55 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/05 19:41:23 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction_set.h"

void	pa(t_list *a, t_list *b)
{
	void	*content;

	if (!a || !b)
		return ;
	content = list_pop_front(b);
	if (content)
		list_push_front(a, content);
}

void	pb(t_list *a, t_list *b)
{
	void	*content;

	if (!a || !b)
		return ;
	content = list_pop_front(a);
	if (content)
		list_push_front(b, content);
}

void	sa(t_list *a)
{
	void	*first;
	void	*second;

	if (!a || list_size(a) < 2)
		return ;
	first = list_pop_front(a);
	second = list_pop_front(a);
	list_push_front(a, first);
	list_push_front(a, second);
}

void	sb(t_list *b)
{
	void	*first;
	void	*second;

	if (!b || list_size(b) < 2)
		return ;
	first = list_pop_front(b);
	second = list_pop_front(b);
	list_push_front(b, first);
	list_push_front(b, second);
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
}
