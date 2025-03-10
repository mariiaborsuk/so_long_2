/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_p_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:39:35 by mborsuk       #+  #+#    #+#             */
/*   Updated: 2025/03/01 12:08:59 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	check_player_or_exit_count(char **ar, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (ar[i])
	{
		j = 0;
		while (ar[i][j])
		{
			if (ar[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	else
		write(1, "Error\nThere should be one player and exit position\n", 52);
	return (0);
}
