/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 00:00:00 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/05 19:45:08 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_H
# define RUN_H

# include "instruction_set.h"
# include "parsing.h"

typedef enum e_strategy
{
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX
}	t_strategy;

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_operation;

typedef struct s_run
{
	t_list			*a;
	t_list			*b;
	t_strategy		strategy;
	t_strategy		effective_strategy;
	float			disorder;
	int				bench;
	unsigned int	operations[OP_COUNT];
	unsigned int	total_operations;
}	t_run;

t_run		*run_create(int argc, char **argv);
void		run_destroy(t_run *run);
void		run_report(const t_run *run);
const char	*run_strategy_name(t_strategy strategy);
const char	*run_strategy_complexity(t_strategy strategy);

void		run_sa(t_run *run);
void		run_sb(t_run *run);
void		run_ss(t_run *run);
void		run_pa(t_run *run);
void		run_pb(t_run *run);
void		run_ra(t_run *run);
void		run_rb(t_run *run);
void		run_rr(t_run *run);
void		run_rra(t_run *run);
void		run_rrb(t_run *run);
void		run_rrr(t_run *run);
void		run_mark(t_run *run, t_operation operation, const char *name);

#endif