/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operations_reverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 00:00:00 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/24 17:12:44 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

void	run_rrr(t_run *run)
{
	if (!run || (list_size(run->a) < 2 && list_size(run->b) < 2))
		return ;
	rrr(run->a, run->b);
	run_mark(run, OP_RRR, "rrr");
}

void	run_rra(t_run *run)
{
	if (!run || list_size(run->a) < 2)
		return ;
	rra(run->a);
	run_mark(run, OP_RRA, "rra");
}

void	run_rrb(t_run *run)
{
	if (!run || list_size(run->b) < 2)
		return ;
	rrb(run->b);
	run_mark(run, OP_RRB, "rrb");
}
