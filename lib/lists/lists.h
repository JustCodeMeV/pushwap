/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:03:47 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/02 23:38:46 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include <stddef.h>
# include <stdbool.h>

/* Called on each non-NULL content pointer when its node is destroyed,
   if freer is not NULL. */
typedef void	(*t_list_free_fn)(void *ptr);

/* Compare function: return 0 if equal, <0, >0 like strcmp. */
typedef int		(*t_list_cmp_fn)(const void *a, const void *b);

/* Visitor callback for list_foreach. */
typedef void	(*t_list_visit_fn)(void *content, void *ctx);

typedef struct s_list_node
{
	struct s_list_node	*next;
	struct s_list_node	*prev;
	void				*content;
}	t_list_node;

typedef struct s_list
{
	t_list_node			sentinel;
	size_t				size;
	t_list_free_fn		lsfree;
}	t_list;

/* Creation / destruction */

t_list			*list_create(t_list_free_fn freer);
void			list_destroy(t_list *list);

/* Basic properties */

int				list_empty(const t_list *list);
size_t			list_size(const t_list *list);

/* Push / pop (front/back) */

/* On allocation failure, the list does not take ownership of content. */
t_list_node		*list_push_front(t_list *list, void *content);
t_list_node		*list_push_back(t_list *list, void *content);

/* Pop transfers payload ownership to the caller, or returns NULL if empty. */

void			*list_pop_front(t_list *list);
void			*list_pop_back(t_list *list);

/* Insert relative to an existing node.
	On allocation failure, the list does not take ownership of content. */

t_list_node		*list_insert_before(t_list *l, t_list_node *p, void *c);
t_list_node		*list_insert_after(t_list *l, t_list_node *p, void *c);

/* Erase a node:
	- list_erase: frees node and its non-NULL content via freer
	- list_remove_node: frees node and transfers content to the caller */

void			list_erase(t_list *list, t_list_node *node);
void			*list_remove_node(t_list *list, t_list_node *node);

/* Search */

t_list_node		*list_find(const t_list *l, const void *k, t_list_cmp_fn cmp);

/* Rotation: circular, so rotate in O(1) by moving one node. */

void			list_rotate_cw(t_list *list);/* last -> front */
void			list_rotate_ccw(t_list *list);/* first -> back  */

/* Clear all nodes, freeing their non-NULL content via freer.
	The list object itself stays valid. */

void			list_clear(t_list *list);

/* Traversal helpers */

void			list_foreach(t_list *list, t_list_visit_fn fn, void *ctx);

t_list_node		*list_first(const t_list *list);
t_list_node		*list_last(const t_list *list);
t_list_node		*list_next(const t_list *list, const t_list_node *node);
t_list_node		*list_prev(const t_list *list, const t_list_node *node);
void			*list_content(const t_list_node *node);

#endif /* LIST_H */
