/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mborsuk <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/01 10:47:29 by mborsuk       #+#    #+#                 */
/*   Updated: 2025/03/05 11:26:55 by mborsuk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "display_map.h"
#include "map.h"

void	put_victory_message(t_expose_data *data)
{
	mlx_clear_window(data->m_p, data->w_p);
	mlx_string_put(data->m_p, data->w_p, data->map->x / 2 * CELL_W, data->map->y
		/ 2 * CELL_H, 0xFFCC00, "YOU WON!!!!! GLORIOUS VICTORY!!!");
	data->map->is_victory = 1;
}

void	put_defeat_message(t_expose_data *data)
{
	mlx_clear_window(data->m_p, data->w_p);
	mlx_string_put(data->m_p, data->w_p, data->map->x / 2 * CELL_W, data->map->y
		/ 2 * CELL_H, 0xFF0000, "You LOST!!! WHAT A SHAME!!!");
	data->map->lost = 1;
}

int	should_move(t_expose_data *data, int x, int y)
{
	if (data->map->is_victory == 1 || data->map->lost == 1)
		return (0);
	if (data->map->cells[y][x]->state == CELL_WALL)
		return (0);
	if (data->map->cells[y][x]->state == CELL_EXIT_LOCKED)
		return (0);
	return (1);
}

void	check_collectible(t_expose_data *data, int x, int y)
{
	t_cell	*exit_cell;

	exit_cell = data->map->cells[data->map->exit_pos.y][data->map->exit_pos.x];
	if (data->map->cells[y][x]->state == CELL_COLLECTIBLE)
	{
		data->map->collectibles--;
		if (data->map->collectibles == 0)
		{
			exit_cell->state = CELL_EXIT_UNLOCKED;
			draw_cell(data, data->map->exit_pos.x, data->map->exit_pos.y);
		}
	}
}

void	move_player(t_expose_data *data, int x, int y)
{
	data->map->cells[y][x]->state = CELL_PLAYER;
	data->map->cells[data->map->pl_p.y][data->map->pl_p.x]->state = CELL_EMPTY;
	draw_cell(data, x, y);
	draw_cell(data, data->map->pl_p.x, data->map->pl_p.y);
	data->map->pl_p.x = x;
	data->map->pl_p.y = y;
	data->map->moves++;
	draw_moves(data->map);
}
