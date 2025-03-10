/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:37:41 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 18:33:07 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"
#include "../src/free_functions.h"
#include <stdio.h>
#include <stdlib.h>

int	count_lines(char const *str, char c)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			lines++;
		}
		i++;
	}
	return (lines);
}

static int	ft_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int start, int len)
{
	int	j;

	j = 0;
	while (j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **strs, int count)
{
	int	i;
	int	word;
	int	start;

	i = 0;
	word = 0;
	while (word < count)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		strs[word] = malloc(sizeof(char) * (i - start + 1));
		if (!strs[word])
		{
			free_fn(strs);
			return (NULL);
		}
		ft_putword(strs[word++], s, start, i - start);
	}
	strs[word] = NULL;
	return (strs);
}

void	ft_split(char const *s, char c, t_split *split)
{
	char	**strs;
	int		count;
	int		lines;

	if (!s)
		return ;
	count = ft_count(s, c);
	lines = count_lines(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
	{
		free_fn(strs);
		return ;
	}
	split->ar = ft_split_words(s, c, strs, count);
	split->line_count = lines;
}
