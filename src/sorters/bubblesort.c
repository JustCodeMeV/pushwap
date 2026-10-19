/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:30:17 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/19 16:35:31 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorters.h"

static void	rotate_back(t_run *run, size_t count)
{
	while (count > 0)
	{
		run_rra(run);
		count--;
	}
}

static int	bubble_pass(t_run *run, size_t limit)
{
	size_t		count;
	int			sorted;
	t_list_node	*first;
	t_list_node	*second;

	sorted = 0;
	count = 0;
	while (count < limit)
	{
		first = list_first(run->a);
		second = list_next(run->a, first);
		if (*(int *)list_content(first) > *(int *)list_content(second))
		{
			run_sa(run);
			sorted = 1;
		}
		run_ra(run);
		count++;
	}
	rotate_back(run, limit);
	return (sorted);
}

void	bubblesort(t_run *run)
{
	size_t	size;

	if (!run || list_size(run->a) < 2)
		return ;
	size = list_size(run->a) - 1;
	while (size > 0 && bubble_pass(run, size))
	{
		size--;
	}
}
