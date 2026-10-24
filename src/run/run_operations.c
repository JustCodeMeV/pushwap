/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 00:00:00 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/24 17:30:40 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"
#include "libft.h"

void	run_mark(t_run *run, t_operation operation, const char *name)
{
	run->operations[operation]++;
	run->total_operations++;
	ft_printf("%s\n", name);
}

void	run_sa(t_run *run)
{
	if (!run || list_size(run->a) < 2)
		return ;
	sa(run->a);
	run_mark(run, OP_SA, "sa");
}

void	run_sb(t_run *run)
{
	if (!run || list_size(run->b) < 2)
		return ;
	sb(run->b);
	run_mark(run, OP_SB, "sb");
}

void	run_ss(t_run *run)
{
	if (!run || (list_size(run->a) < 2 && list_size(run->b) < 2))
		return ;
	ss(run->a, run->b);
	run_mark(run, OP_SS, "ss");
}
