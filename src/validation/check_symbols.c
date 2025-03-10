/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:40:30 by mborsuk       #+  #+#    #+#             */
/*   Updated: 2025/03/01 12:09:12 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_strjoin.h"
#include "unistd.h"

int	check_allowed_symbols(char **ar)
{
	int	i;
	int	j;

	i = 0;
	while (ar[i])
	{
		j = 0;
		while (ar[i][j])
		{
			if (!ft_strchr("01CPED", ar[i][j]))
			{
				write(1, "Error\nMap file contains invalid symbols\n", 41);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
