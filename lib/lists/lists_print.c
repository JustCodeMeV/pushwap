/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 20:35:59 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/24 17:17:56 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_private.h"
#include "ft_printf.h"

void	print_list(const char *label, t_list *list)
{
	t_list_node	*it;
	int			*value;

	ft_printf("%s: ", label);
	if (list_empty(list))
	{
		ft_printf("(empty)\n");
		return ;
	}
	it = list_first(list);
	while (it)
	{
		value = list_content(it);
		ft_printf("%d", *value);
		if (list_next(list, it))
			ft_printf(" -> ");
		it = list_next(list, it);
	}
	ft_printf("\n");
}
