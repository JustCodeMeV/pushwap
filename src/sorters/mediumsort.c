/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediumsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 00:00:00 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/19 16:35:28 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorters.h"

/* Ranks are calculated across both stacks, so moving a value keeps its rank. */
static size_t	value_rank(t_run *run, int value)
{
	t_list_node	*node;
	size_t		rank;

	rank = 0;
	node = list_first(run->a);
	while (node)
	{
		if (*(int *)list_content(node) < value)
			rank++;
		node = list_next(run->a, node);
	}
	node = list_first(run->b);
	while (node)
	{
		if (*(int *)list_content(node) < value)
			rank++;
		node = list_next(run->b, node);
	}
	return (rank);
}

static size_t	find_max_position(t_run *run, size_t *max_rank)
{
	t_list_node	*node;
	size_t		position;
	size_t		best_position;
	size_t		rank;

	node = list_first(run->b);
	position = 0;
	best_position = 0;
	*max_rank = 0;
	while (node)
	{
		rank = value_rank(run, *(int *)list_content(node));
		if (rank >= *max_rank)
		{
			*max_rank = rank;
			best_position = position;
		}
		position++;
		node = list_next(run->b, node);
	}
	return (best_position);
}

/* Push one sqrt-sized rank range at a time; rotate small values deeper in b. */
static void	push_chunks(t_run *run, size_t size, size_t chunk)
{
	size_t	low;
	size_t	high;
	size_t	checks;
	size_t	rank;

	low = 0;
	while (low < size)
	{
		high = low + chunk;
		checks = list_size(run->a);
		while (checks-- > 0)
		{
			rank = value_rank(run, *(int *)list_content(list_first(run->a)));
			if (rank < high)
			{
				run_pb(run);
				if (rank < low + chunk / 2)
					run_rb(run);
			}
			else
				run_ra(run);
		}
		low += chunk;
	}
}

/* The largest remaining rank is brought to b's top before each push to a. */
static void	pull_sorted(t_run *run)
{
	size_t	position;
	size_t	max_rank;
	size_t	b_size;

	while (!list_empty(run->b))
	{
		position = find_max_position(run, &max_rank);
		b_size = list_size(run->b);
		if (position <= b_size / 2)
			while (position-- > 0)
				run_rb(run);
		else
			while (position++ < b_size)
				run_rrb(run);
		run_pa(run);
	}
}

/* Chunking limits the range-processing work to the medium strategy class. */
void	mediumsort(t_run *run)
{
	size_t	chunk;
	size_t	size;

	if (!run || list_size(run->a) < 2)
		return ;
	size = list_size(run->a);
	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	push_chunks(run, size, chunk);
	pull_sorted(run);
}
