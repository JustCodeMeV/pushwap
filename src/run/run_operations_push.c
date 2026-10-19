/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operations_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 00:00:00 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/05 19:41:52 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

void	run_pa(t_run *run)
{
	if (!run || list_empty(run->b))
		return ;
	pa(run->a, run->b);
	run_mark(run, OP_PA, "pa");
}

void	run_pb(t_run *run)
{
	if (!run || list_empty(run->a))
		return ;
	pb(run->a, run->b);
	run_mark(run, OP_PB, "pb");
}
