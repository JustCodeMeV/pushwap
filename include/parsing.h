/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:16:45 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/04 19:12:36 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "lists.h"

int		*parse_args(int argc, char **argv, int *count_out);
int		*parse_args_from(int argc, char **argv, int start, int *count_out);
float	get_disorder(t_list *list);

#endif