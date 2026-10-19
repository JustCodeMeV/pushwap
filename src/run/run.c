/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 00:00:00 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/20 20:26:02 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"
#include <stdio.h>
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

void	run_report(const t_run *run)
{
	if (!run || !run->bench)
		return ;
	fprintf(stderr, "[bench] disorder: %.2f%%\n", run->disorder * 100.0f);
	fprintf(stderr, "[bench] strategy: %s / %s\n",
		run_strategy_name(run->strategy),
		run_strategy_complexity(run->effective_strategy));
	fprintf(stderr, "[bench] total_ops: %u\n", run->total_operations);
	fprintf(stderr, "[bench] sa: %u sb: %u ss: %u pa: %u pb: %u\n",
		run->operations[OP_SA], run->operations[OP_SB],
		run->operations[OP_SS], run->operations[OP_PA],
		run->operations[OP_PB]);
	fprintf(stderr, "[bench] ra: %u rb: %u rr: %u rra: %u rrb: %u rrr: %u\n",
		run->operations[OP_RA], run->operations[OP_RB],
		run->operations[OP_RR], run->operations[OP_RRA],
		run->operations[OP_RRB], run->operations[OP_RRR]);
}
