/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:44:30 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 18:32:45 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_map.h"
#include "free_functions.h"
#include "map.h"
#include "maps_utils.h"
#include <stdlib.h>
#include <unistd.h>

void	free_lib(t_expose_data *data)
{
	free_image_pointers(data->m_p);
	mlx_loop_end(data->m_p);
	mlx_destroy_window(data->m_p, data->w_p);
	mlx_destroy_display(data->m_p);
	free(data->m_p);
	data->m_p = NULL;
	data->w_p = NULL;
	free_map(data->map);
	free(data);
	data = NULL;
	exit(0);
}

void	free_map(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			free(map->cells[i][j]);
			map->cells[i][j] = NULL;
			++j;
		}
		free(map->cells[i]);
		map->cells[i] = NULL;
		++i;
	}
	free(map->cells);
	map->cells = NULL;
	free(map);
	map = NULL;
}

int	destroy_window(void *m_p)
{
	mlx_destroy_display(m_p);
	free(m_p);
	write(1, "Error\n", 6);
	return (1);
}

void	free_substrings(char **substrings)
{
	int	i;

	i = 0;
	while (substrings[i])
	{
		free(substrings[i]);
		i++;
	}
	free(substrings);
}

void	free_fn(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
