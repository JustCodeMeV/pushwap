/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*	 Created: 2026/08/19 17:19:48 by vrouxel		   #+#	  #+#			  */
/*   Updated: 2026/09/05 19:42:39 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"
#include "sorters.h"
#include "libft.h"

void	sort(t_run *run)
{
	if (list_size(run->a) <= 5)
		smallsort(run);
	else if (run->effective_strategy == STRATEGY_SIMPLE)
		bubblesort(run);
	else if (run->effective_strategy == STRATEGY_MEDIUM)
		mediumsort(run);
	else if (run->effective_strategy == STRATEGY_COMPLEX)
		radixsort(run);
}

int	main(int argc, char **argv)
{
	t_run	*run;

	run = run_create(argc, argv);
	if (!run)
	{
		if (argc > 1)
			ft_putstr_fd("Error\n", 2);
		return (argc > 1);
	}
	if (run->disorder == 0)
	{
		run_report(run);
		run_destroy(run);
		return (0);
	}
	sort(run);
	run_report(run);
	run_destroy(run);
	return (0);
}
