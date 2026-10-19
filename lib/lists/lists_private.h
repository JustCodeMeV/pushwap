/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:04:29 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/02 16:21:55 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_PRIVATE_H
# define LISTS_PRIVATE_H

# include "lists.h"

void			list_init(t_list *list, t_list_free_fn lsfree);
t_list_node		*node_create(void *content);
void			link_between(t_list_node *l, t_list_node *n, t_list_node *r);
void			unlink_node(t_list_node *node);

#endif