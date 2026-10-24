/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:25:30 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/24 17:26:24 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"
#include <stdlib.h>
#include <string.h>

static int	set_flag(t_run *run, const char *arg)
{
	if (!strcmp(arg, "--bench"))
		run->bench = 1;
	else if (!strcmp(arg, "--simple"))
		run->strategy = STRATEGY_SIMPLE;
	else if (!strcmp(arg, "--medium"))
		run->strategy = STRATEGY_MEDIUM;
	else if (!strcmp(arg, "--complex"))
		run->strategy = STRATEGY_COMPLEX;
	else if (!strcmp(arg, "--adaptive"))
		run->strategy = STRATEGY_ADAPTIVE;
	else
		return (0);
	return (1);
}

static t_list	*build_stack(const int *values, int count)
{
	t_list	*stack;
	int		*value;
	int		i;

	stack = list_create(free);
	if (!stack)
		return (NULL);
	i = 0;
	while (i < count)
	{
		value = malloc(sizeof(*value));
		if (!value)
			return (list_destroy(stack), NULL);
		*value = values[i++];
		if (!list_push_back(stack, value))
		{
			free(value);
			return (list_destroy(stack), NULL);
		}
	}
	return (stack);
}

static void	select_strategy(t_run *run)
{
	run->effective_strategy = run->strategy;
	if (run->strategy != STRATEGY_ADAPTIVE)
		return ;
	if (run->disorder < 0.2f)
		run->effective_strategy = STRATEGY_SIMPLE;
	else if (run->disorder < 0.5f)
		run->effective_strategy = STRATEGY_MEDIUM;
	else
		run->effective_strategy = STRATEGY_COMPLEX;
}

static t_run	*create_stacks(t_run *run, int *values, int count)
{
	run->a = build_stack(values, count);
	free(values);
	if (!run->a)
		return (free(run), NULL);
	run->b = list_create(free);
	if (!run->b)
		return (run_destroy(run), NULL);
	run->disorder = get_disorder(run->a);
	select_strategy(run);
	return (run);
}

t_run	*run_create(int argc, char **argv)
{
	t_run	*run;
	int		*values;
	int		count;
	int		start;

	if (argc <= 1)
		return (NULL);
	run = malloc(sizeof(*run));
	if (!run)
		return (NULL);
	run->strategy = STRATEGY_ADAPTIVE;
	start = 1;
	while (start < argc && argv[start][0] == '-'
		&& argv[start][1] == '-')
	{
		if (!set_flag(run, argv[start]))
			return (free(run), NULL);
		start++;
	}
	if (start == argc)
		return (free(run), NULL);
	values = parse_args_from(argc, argv, start, &count);
	if (!values)
		return (free(run), NULL);
	return (create_stacks(run, values, count));
}
