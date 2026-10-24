/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:16:38 by vrouxel           #+#    #+#             */
/*   Updated: 2026/10/24 14:18:15 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_PRIVATE_H
# define PARSING_PRIVATE_H

int	is_digit(char c);
int	is_valid_token(const char *s);
int	parse_int_strict(const char *s, int *out);

#endif
