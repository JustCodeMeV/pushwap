/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:04:58 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/05 19:41:17 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction_set.h"

void	ra(t_list *a)
{
	if (a && list_size(a) >= 2)
		list_rotate_ccw(a);
}

void	rb(t_list *b)
{
	if (b && list_size(b) >= 2)
		list_rotate_ccw(b);
}

void	rr(t_list *a, t_list *b)
{
	ra(a);
	rb(b);
}

void	rra(t_list *a)
{
	if (a && list_size(a) >= 2)
		list_rotate_cw(a);
}

void	rrb(t_list *b)
{
	if (b && list_size(b) >= 2)
		list_rotate_cw(b);
}
