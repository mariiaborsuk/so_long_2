/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:43:22 by mborsuk       #+  #+#    #+#             */
/*   Updated: 2025/03/01 12:06:29 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_map.h"
#include "map.h"
#include "maps_utils.h"

void	draw_cell(t_expose_data *data, int x, int y)
{
	t_image_pointers	*i_p;

	i_p = get_image_pointers();
	if (data->map->cells[y][x]->state == CELL_WALL)
		mlx_put_image_to_window(data->m_p, data->w_p, i_p->image_wall,
			x * CELL_W, y * CELL_H);
	else if (data->map->cells[y][x]->state == CELL_EMPTY)
		mlx_put_image_to_window(data->m_p, data->w_p, i_p->image_space,
			x * CELL_W, y * CELL_H);
	else if (data->map->cells[y][x]->state == CELL_PLAYER)
		mlx_put_image_to_window(data->m_p, data->w_p, i_p->image_player,
			x * CELL_W, y * CELL_H);
	else if (data->map->cells[y][x]->state == CELL_EXIT_LOCKED)
		mlx_put_image_to_window(data->m_p, data->w_p, i_p->image_locked_exit,
			x * CELL_W, y * CELL_H);
	else if (data->map->cells[y][x]->state == CELL_EXIT_UNLOCKED)
		mlx_put_image_to_window(data->m_p, data->w_p, i_p->image_unlocked,
			x * CELL_W, y * CELL_H);
	else if (data->map->cells[y][x]->state == CELL_COLLECTIBLE)
		mlx_put_image_to_window(data->m_p, data->w_p, i_p->image_collectible,
			x * CELL_W, y * CELL_H);
	else if (data->map->cells[y][x]->state == CELL_DANGER)
		mlx_put_image_to_window(data->m_p, data->w_p, i_p->danger,
			x * CELL_W, y * CELL_H);
}

void	draw_map(t_expose_data *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < data->map->y)
	{
		j = 0;
		while (j < data->map->x)
		{
			draw_cell(data, j, i);
			j++;
		}
		i++;
	}
	draw_moves(data->map);
}

void	write_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	draw_moves(t_map *map)
{
	char	*str;
	char	*str1;
	char	*number_of_moves;
	char	*collectibles;

	str = NULL;
	str1 = NULL;
	number_of_moves = NULL;
	number_of_moves = ft_itoa(map->moves);
	collectibles = NULL;
	collectibles = ft_itoa(map->collectibles);
	if (!number_of_moves || !collectibles)
		return ;
	ft_strjoin(&str, "Movements:  ");
	ft_strjoin(&str, number_of_moves);
	ft_strjoin(&str1, "Collectibles: to gather: ");
	ft_strjoin(&str1, collectibles);
	write_str(str);
	write_str(str1);
	free(str);
	free(str1);
	free(collectibles);
	free(number_of_moves);
}
