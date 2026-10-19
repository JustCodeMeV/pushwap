/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:16:34 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/05 19:41:36 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <limits.h>

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_token(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!is_digit(s[i]))
		return (0);
	while (s[i])
	{
		if (!is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_sign(const char *s, int *index)
{
	int	sign;

	sign = 1;
	if (s[*index] == '+' || s[*index] == '-')
	{
		if (s[*index] == '-')
			sign = -1;
		(*index)++;
	}
	return (sign);
}

static int	parse_digits(const char *s, int index, long long limit,
	long long *result)
{
	long long	acc;
	int			digit;

	acc = 0;
	while (s[index])
	{
		digit = s[index++] - '0';
		if (acc > (limit - digit) / 10)
			return (0);
		acc = acc * 10 + digit;
	}
	*result = acc;
	return (1);
}

int	parse_int_strict(const char *s, int *out)
{
	long long	limit;
	long long	acc;
	int			sign;
	int			i;

	if (!is_valid_token(s) || !out)
		return (0);
	i = 0;
	sign = parse_sign(s, &i);
	if (sign == 1)
		limit = INT_MAX;
	else
		limit = -(long long)INT_MIN;
	if (!parse_digits(s, i, limit, &acc))
		return (0);
	if (sign == 1)
		*out = (int)acc;
	else
		*out = (int)(-acc);
	return (1);
}
