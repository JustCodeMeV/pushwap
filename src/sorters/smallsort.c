/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:50:34 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/19 19:18:03 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorters.h"

static size_t	find_min_index(t_run *run, size_t size)
{
	t_list_node	*node;
	size_t		index;
	size_t		min_index;
	int			min_value;

	node = list_first(run->a);
	min_value = *(int *)list_content(node);
	min_index = 0;
	index = 1;
	while (index < size)
	{
		node = list_next(run->a, node);
		if (*(int *)list_content(node) < min_value)
		{
			min_value = *(int *)list_content(node);
			min_index = index;
		}
		index++;
	}
	return (min_index);
}

static void	rotate_min(t_run *run, size_t size, size_t min_index)
{
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
			run_ra(run);
	}
	else
	{
		while (min_index++ < size)
			run_rra(run);
	}
}

static void	push_min(t_run *run)
{
	size_t	size;
	size_t	min_index;

	size = list_size(run->a);
	min_index = find_min_index(run, size);
	rotate_min(run, size, min_index);
	run_pb(run);
}

static void	sort_three(t_run *run)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)list_content(list_first(run->a));
	second = *(int *)list_content(list_next(run->a, list_first(run->a)));
	third = *(int *)list_content(list_next(run->a,
				list_next(run->a, list_first(run->a))));
	if (first > second && first > third)
		run_ra(run);
	else if (second > first && second > third)
		run_rra(run);
	if (*(int *)list_content(list_first(run->a))
		> *(int *)list_content(list_next(run->a, list_first(run->a))))
		run_sa(run);
}

void	smallsort(t_run *run)
{
	size_t	size;

	if (!run || list_size(run->a) < 2)
		return ;
	size = list_size(run->a);
	if (size > 3)
	{
		push_min(run);
		if (size == 5)
			push_min(run);
	}
	if (list_size(run->a) == 3)
		sort_three(run);
	else if (list_size(run->a) == 2
		&& *(int *)list_content(list_first(run->a))
		> *(int *)list_content(list_next(run->a, list_first(run->a))))
		run_sa(run);
	while (!list_empty(run->b))
		run_pa(run);
}
