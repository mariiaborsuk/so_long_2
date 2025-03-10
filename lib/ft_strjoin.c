/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:31:22 by mborsuk       #+  #+#    #+#             */
/*   Updated: 2025/03/01 12:06:19 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, const char c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return ((char *)(s + i));
		++i;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

void	ft_strjoin(char **s1, const char *s2)
{
	char	*result;
	int		i;
	int		j;
	int		len1;
	int		len2;

	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
	{
		free(*s1);
		*s1 = NULL;
		return ;
	}
	i = -1;
	while (++i < len1)
		result[i] = (*s1)[i];
	j = -1;
	while (++j < len2)
		result[i + j] = s2[j];
	result[i + j] = '\0';
	free(*s1);
	*s1 = result;
}
