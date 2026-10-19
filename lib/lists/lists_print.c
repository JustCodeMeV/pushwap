/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 20:35:59 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/20 21:30:05 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_private.h"
#include <stdio.h>

void	print_list(const char *label, t_list *list)
{
	t_list_node	*it;
	int			*value;

	printf("%s: ", label);
	if (list_empty(list))
	{
		printf("(empty)\n");
		return ;
	}
	it = list_first(list);
	while (it)
	{
		value = list_content(it);
		printf("%d", *value);
		if (list_next(list, it))
			printf(" -> ");
		it = list_next(list, it);
	}
	printf("\n");
}
