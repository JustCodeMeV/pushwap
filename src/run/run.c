/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 00:00:00 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/24 14:31:04 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"
#include "libft.h"
#include <stdlib.h>

void	run_destroy(t_run *run)
{
	if (!run)
		return ;
	list_destroy(run->a);
	list_destroy(run->b);
	free(run);
}

const char	*run_strategy_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("Simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("Medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

const char	*run_strategy_complexity(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRATEGY_MEDIUM)
		return ("O(n sqrt(n))");
	return ("O(n log(n))");
}

static void	run_report_operations(const t_run *run)
{
	const char	*names[OP_COUNT] = {
		"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"
	};
	int			i;

	ft_putstr_fd("\n[bench] ", 2);
	i = 0;
	while (i < OP_COUNT)
	{
		if (i == OP_RA)
			ft_putstr_fd("\n[bench] ", 2);
		if (i > 0 && i != OP_RA)
			ft_putstr_fd(" ", 2);
		ft_putstr_fd(names[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(run->operations[i], 2);
		i++;
	}
	ft_putstr_fd("\n", 2);
}

void	run_report(const t_run *run)
{
	if (!run || !run->bench)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putfloat_fd(run->disorder * 100.0f, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(run_strategy_name(run->strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(run_strategy_complexity(run->effective_strategy), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(run->total_operations, 2);
	run_report_operations(run);
}
