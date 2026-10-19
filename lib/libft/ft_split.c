/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:39:44 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/23 14:39:49 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int		count;
	size_t	i;
	size_t	x;

	count = 0;
	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (s[i] == c)
			x = 0;
		i++;
	}
	return (count);
}

static void	*free_all(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	*get_token(const char *s, int head, int tail)
{
	char	*tok;
	int		i;

	i = 0;
	tok = malloc((tail - head + 1) * sizeof(char));
	if (!tok)
		return (NULL);
	while (head < tail)
	{
		tok[i] = s[head];
		i++;
		head++;
	}
	tok[i] = 0;
	return (tok);
}

static char	**tokenize(char **tab, const char *s, char c)
{
	size_t			i;
	size_t			j;
	int				is_tok;
	const size_t	len = ft_strlen(s);

	i = 0;
	j = 0;
	is_tok = -1;
	while (i <= len)
	{
		if (s[i] != c && is_tok < 0)
			is_tok = i;
		else if ((s[i] == c || i == len) && is_tok >= 0)
		{
			tab[j] = get_token(s, is_tok, i);
			if (!(tab[j]))
				return (free_all(tab, j));
			is_tok = -1;
			j++;
		}
		i++;
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char			**tab;

	if (!s)
		return (NULL);
	tab = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	return (tokenize(tab, s, c));
}
