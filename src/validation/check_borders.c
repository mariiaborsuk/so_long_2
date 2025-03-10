/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:38:39 by mborsuk       #+  #+#    #+#             */
/*   Updated: 2025/03/01 12:08:38 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "../map.h"
#include "../utils_2.h"

int	check_borders(char **ar)
{
	int	i;
	int	len;

	i = 0;
	while (ar[0][i])
	{
		if (ar[0][i] != '1')
		{
			write(1, "Error\nBorders are not valid\n", 29);
			return (0);
		}
		i++;
	}
	i = 0;
	len = get_ar_len(ar);
	while (ar[len - 1][i])
	{
		if (ar[len - 1][i] != '1')
		{
			write(1, "Error\nBorders are not valid\n", 29);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_sides(char **ar)
{
	int	i;
	int	ar_len;
	int	len;

	i = 1;
	ar_len = get_ar_len(ar);
	while (i < (ar_len - 1))
	{
		len = get_len(ar[i]);
		if (ar[i][0] != '1' || ar[i][len - 1] != '1')
		{
			write(1, "Error\nBorders are not valid\n", 29);
			return (0);
		}
		i++;
	}
	return (1);
}
