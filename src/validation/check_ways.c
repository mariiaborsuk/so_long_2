/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:41:01 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/06 11:08:34 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../free_functions.h"
#include "../map.h"
#include "../maps_utils.h"
#include "../movement_utils.h"
#include "../utils_2.h"
#include "validation.h"
#include <stdio.h>

void	check_way(t_c *coords, char **ar)
{
	int	start_x;
	int	start_y;

	if (coords->start_x > -1 && coords->start_y > -1)
	{
		start_x = coords->start_x;
		start_y = coords->start_y;
		modify_ar(ar, start_y, start_x);
	}
}

void	find_position(char **ar, int size, t_c *coords, char symbol)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (ar[i][++j] != '\0')
		{
			if (ar[i][j] == symbol)
			{
				coords->start_x = j;
				coords->start_y = i;
				break ;
			}
		}
		if (coords->start_x != -1)
			break ;
	}
}

void	init_coords(t_c *coords)
{
	coords->start_x = -1;
	coords->start_y = -1;
}

void	modify_ar(char **ar, int start_y, int start_x)
{
	if (start_y < 0 || start_x < 0 || !ar[start_y]
		|| ar[start_y][start_x] == '\0')
		return ;
	if (ar[start_y][start_x] == '1' || ar[start_y][start_x] == 'E')
		return ;
	if (ar[start_y][start_x] == 'F')
		return ;
	if (ar[start_y][start_x] == 'D')
		return ;
	if (ar[start_y][start_x] != 'P')
		ar[start_y][start_x] = 'F';
	modify_ar(ar, start_y - 1, start_x);
	modify_ar(ar, start_y + 1, start_x);
	modify_ar(ar, start_y, start_x - 1);
	modify_ar(ar, start_y, start_x + 1);
}

int	check_ways(char **ar)
{
	char				**ar_copy;
	t_all_coordinates	all_c;

	ar_copy = copy_array(ar, get_ar_len(ar));
	init_coords(&all_c.player_pos);
	init_coords(&all_c.exit_pos);
	find_position(ar_copy, get_ar_len(ar), &all_c.player_pos, CELL_PLAYER);
	find_position(ar_copy, get_ar_len(ar), &all_c.exit_pos, CELL_EXIT_LOCKED);
	all_c.collectible_pos = get_collectible_coordinates(ar_copy);
	if (!all_c.collectible_pos)
	{
		free_substrings(ar_copy);
		return (0);
	}
	check_way(&all_c.player_pos, ar_copy);
	if (!check_all_positions(ar_copy, &all_c.player_pos, &all_c.exit_pos,
			all_c.collectible_pos))
	{
		free_substrings(ar_copy);
		free(all_c.collectible_pos);
		return (0);
	}
	free_substrings(ar_copy);
	free(all_c.collectible_pos);
	return (1);
}
