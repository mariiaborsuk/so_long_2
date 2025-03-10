/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:38:57 by mborsuk       #+  #+#    #+#             */
/*   Updated: 2025/03/01 12:08:45 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	check_collectibles(char **ar)
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
			if (ar[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count > 0)
		return (1);
	else
		write(1, "Error\nThere should be at least one collectible on map\n",
			55);
	return (0);
}
