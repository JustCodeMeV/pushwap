/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operations_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 00:00:00 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/24 17:12:56 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

void	run_ra(t_run *run)
{
	if (!run || list_size(run->a) < 2)
		return ;
	ra(run->a);
	run_mark(run, OP_RA, "ra");
}

void	run_rb(t_run *run)
{
	if (!run || list_size(run->b) < 2)
		return ;
	rb(run->b);
	run_mark(run, OP_RB, "rb");
}

void	run_rr(t_run *run)
{
	if (!run || (list_size(run->a) < 2 && list_size(run->b) < 2))
		return ;
	rr(run->a, run->b);
	run_mark(run, OP_RR, "rr");
}
