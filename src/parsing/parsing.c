/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:16:42 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/05 19:41:42 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "parsing_private.h"
#include <stdlib.h>

static int	has_duplicate(const int *values, int count, int value)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (values[i] == value)
			return (1);
		i++;
	}
	return (0);
}

static int	parse_values(char **argv, int start, int argc, int *values)
{
	int	count;
	int	value;
	int	i;

	count = 0;
	i = start;
	while (i < argc)
	{
		if (!parse_int_strict(argv[i], &value)
			|| has_duplicate(values, count, value))
			return (-1);
		values[count] = value;
		count++;
		i++;
	}
	return (count);
}

int	*parse_args_from(int argc, char **argv, int start, int *count_out)
{
	int	*values;

	if (!count_out || start < 1 || argc <= start)
		return (NULL);
	*count_out = 0;
	values = malloc(sizeof(*values) * (argc - start));
	if (!values)
		return (NULL);
	*count_out = parse_values(argv, start, argc, values);
	if (*count_out < 0)
	{
		free(values);
		return (NULL);
	}
	return (values);
}

int	*parse_args(int argc, char **argv, int *count_out)
{
	return (parse_args_from(argc, argv, 1, count_out));
}
