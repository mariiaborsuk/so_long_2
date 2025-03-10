/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:39:13 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 18:37:02 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			last = s;
		}
		s++;
	}
	if (*s == (unsigned char)c)
	{
		last = s;
	}
	return ((char *)last);
}

int	check_file_extension(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i > 4)
	{
		if (filename[i - 5] == '/')
		{
			write(1, "Error\nWrong extension\n", 23);
			return (0);
		}
		if (filename[i - 1] == 'r' && filename[i - 2] == 'e' && filename[i
				- 3] == 'b' && filename[i - 4] == '.')
			return (1);
	}
	write(1, "Error\nWrong extension\n", 23);
	return (0);
}
