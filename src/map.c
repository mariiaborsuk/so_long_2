/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:00:23 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 18:57:27 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./validation/validation.h"
#include "free_functions.h"
#include "map.h"
#include "maps_utils.h"
#include "utils_2.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	modify_map(t_map *map, char **ar, int i, int j)
{
	map->cells[i][j]->value = ar[i][j];
	map->cells[i][j]->state = ar[i][j];
	map->cells[i][j]->x = j;
	map->cells[i][j]->y = i;
	if (map->cells[i][j]->state == CELL_PLAYER)
	{
		map->pl_p.x = j;
		map->pl_p.y = i;
	}
	if (map->cells[i][j]->state == CELL_COLLECTIBLE)
	{
		map->collectibles++;
	}
	if (map->cells[i][j]->state == CELL_EXIT_LOCKED)
	{
		map->exit_pos.x = j;
		map->exit_pos.y = i;
	}
	if (map->cells[i][j]->state == CELL_DANGER)
	{
		map->danger.x = j;
		map->danger.y = i;
	}
}

char	**read_file(char *file_name)
{
	static char	*str;
	t_split		split;

	split.ar = NULL;
	split.line_count = 0;
	str = read_file_contents(file_name);
	ft_split(str, '\n', &split);
	if (!get_ar_len(split.ar))
		return (NULL);
	if (split.line_count > get_ar_len(split.ar))
	{
		free(str);
		free_fn(split.ar);
		write(1, "Error\n Not rectangular.\n", 25);
		return (NULL);
	}
	free(str);
	return (split.ar);
}

void	init_map(t_map *map, char **file_lines)
{
	int	i;
	int	size;

	map->collectibles = 0;
	map->x = 0;
	map->y = 0;
	map->moves = 0;
	map->is_victory = 0;
	map->lost = 0;
	i = 0;
	size = get_ar_len(file_lines);
	map->y = size;
	map->x = get_len(file_lines[i]);
	map->cells = malloc(sizeof(t_cell **) * (size + 1));
}

void	fill_map_cells(t_map *map, char **file_lines)
{
	int	i;
	int	j;

	i = 0;
	while (file_lines[i])
	{
		map->cells[i] = malloc(sizeof(t_cell *) * (get_len(file_lines[i]) + 1));
		if (!map->cells[i])
		{
			free(map->cells);
			return ;
		}
		j = 0;
		while (file_lines[i][j])
		{
			map->cells[i][j] = (t_cell *)malloc(sizeof(t_cell));
			if (!map->cells[i][j])
				return ((void)free(map->cells[i]));
			modify_map(map, file_lines, i, j);
			j++;
		}
		i++;
	}
}

t_map	*parse_map(char *file_name)
{
	char	**ar;
	t_map	*map;

	if (!check_file_extension(file_name))
		exit(1);
	ar = read_file(file_name);
	if (get_ar_len(ar) == 0)
	{
		write(1, "Error\n Empty file\n", 19);
		return (NULL);
	}
	if (!map_val(ar))
	{
		if (ar != NULL)
			free_substrings(ar);
		return (NULL);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map(map, ar);
	fill_map_cells(map, ar);
	free_substrings(ar);
	return (map);
}
