/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:20:54 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/19 16:35:24 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorters.h"

/* Relative ranks let radix sort handle negative and positive input values. */
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

/* Calculate how many binary digits are needed for ranks from zero to n - 1. */
static size_t	bit_count(size_t size)
{
	size_t	bits;
	size_t	limit;

	bits = 0;
	limit = 1;
	while (limit < size)
	{
		limit *= 2;
		bits++;
	}
	return (bits);
}

/* Stable LSD pass:
keep one bit in a and temporarily move zero bits to b. */
static void	sort_bit(t_run *run, size_t size, size_t bit)
{
	size_t	count;
	size_t	rank;

	count = size;
	while (count-- > 0)
	{
		rank = value_rank(run, *(int *)list_content(list_first(run->a)));
		if ((rank >> bit) & 1)
			run_ra(run);
		else
			run_pb(run);
	}
	while (!list_empty(run->b))
		run_pa(run);
}

/* Repeating stable bit passes sorts all 
normalized ranks in O(n log n) moves. */
void	radixsort(t_run *run)
{
	size_t	size;
	size_t	bit;
	size_t	bits;

	if (!run || list_size(run->a) < 2)
		return ;
	size = list_size(run->a);
	bits = bit_count(size);
	bit = 0;
	while (bit < bits)
		sort_bit(run, size, bit++);
}
