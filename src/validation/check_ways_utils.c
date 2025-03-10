/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ways_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:40:42 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/08 21:59:51 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"
#include "../utils_1.h"
#include "unistd.h"
#include "validation.h"

char	**copy_array(char **array, int size)
{
	char	**ar_copy;
	int		i;

	ar_copy = malloc((size + 1) * sizeof(char *));
	if (!ar_copy)
		return (NULL);
	i = 0;
	while (array[i])
	{
		ar_copy[i] = ft_strdup(array[i]);
		if (!ar_copy[i])
			return (NULL);
		i++;
	}
	ar_copy[i] = NULL;
	return (ar_copy);
}

int	count_collectibles(char **array)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
			if (array[i][j] == CELL_COLLECTIBLE)
				count++;
	}
	return (count);
}

t_c	*get_collectible_coordinates(char **array)
{
	t_c	*collectible_coords;
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	collectible_coords = malloc(sizeof(t_c) * (count_collectibles(array) + 1));
	if (!collectible_coords)
		return (NULL);
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
		{
			if (array[i][j] == CELL_COLLECTIBLE)
			{
				collectible_coords[count].start_x = j;
				collectible_coords[count].start_y = i;
				count++;
			}
		}
	}
	init_coords(&collectible_coords[count]);
	return (collectible_coords);
}

int	check_if_position_is_accessible(char **array, t_c *position)
{
	if (ft_strchr("FP", array[position->start_y][position->start_x - 1]))
		return (1);
	if (ft_strchr("FP", array[position->start_y][position->start_x + 1]))
		return (1);
	if (ft_strchr("FP", array[position->start_y - 1][position->start_x]))
		return (1);
	if (ft_strchr("FP", array[position->start_y + 1][position->start_x]))
		return (1);
	return (0);
}

int	check_all_positions(char **array, t_c *player_position, t_c *exit_position,
		t_c *collectible_positions)
{
	int	i;

	if (!check_if_position_is_accessible(array, player_position))
	{
		write(1, "Error\nPlayer position is not accessible\n", 41);
		return (0);
	}
	if (!check_if_position_is_accessible(array, exit_position))
	{
		write(1, "Error\nExit position is not accessible\n", 39);
		return (0);
	}
	i = -1;
	while (collectible_positions[++i].start_x != -1)
	{
		if (!check_if_position_is_accessible(array, &collectible_positions[i]))
		{
			write(1, "Error\nCollectible position is not accessible\n", 46);
			return (0);
		}
	}
	return (1);
}
