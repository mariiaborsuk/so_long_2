/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mborsuk <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 10:02:10 by mborsuk       #+#    #+#                 */
/*   Updated: 2025/03/05 10:06:27 by mborsuk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "display_map.h"
#include "map.h"
#include "maps_utils.h"
#include "movement_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "free_functions.h"

void	move_up(t_expose_data *data)
{
	if (!should_move(data, data->map->pl_p.x, data->map->pl_p.y - 1))
		return ;
	if (data->map->cells[data->map->pl_p.y - 1][data->map->pl_p.x]->state
		== CELL_EXIT_UNLOCKED)
	{
		put_victory_message(data);
		return ;
	}
	if (data->map->cells[data->map->pl_p.y - 1][data->map->pl_p.x]->state
		== CELL_DANGER)
	{
		put_defeat_message(data);
		return ;
	}
	check_collectible(data, data->map->pl_p.x, data->map->pl_p.y - 1);
	move_player(data, data->map->pl_p.x, data->map->pl_p.y - 1);
}

void	move_down(t_expose_data *data)
{
	if (!should_move(data, data->map->pl_p.x, data->map->pl_p.y + 1))
		return ;
	if (data->map->cells[data->map->pl_p.y + 1][data->map->pl_p.x]->state
		== CELL_EXIT_UNLOCKED)
	{
		put_victory_message(data);
		return ;
	}
	if (data->map->cells[data->map->pl_p.y + 1][data->map->pl_p.x]->state
		== CELL_DANGER)
	{
		put_defeat_message(data);
		return ;
	}
	check_collectible(data, data->map->pl_p.x, data->map->pl_p.y + 1);
	move_player(data, data->map->pl_p.x, data->map->pl_p.y + 1);
}

void	move_left(t_expose_data *data)
{
	if (!should_move(data, data->map->pl_p.x - 1, data->map->pl_p.y))
		return ;
	if (data->map->cells[data->map->pl_p.y][data->map->pl_p.x - 1]->state
		== CELL_EXIT_UNLOCKED)
	{
		put_victory_message(data);
		return ;
	}
	if (data->map->cells[data->map->pl_p.y][data->map->pl_p.x - 1]->state
		== CELL_DANGER)
	{
		put_defeat_message(data);
		return ;
	}
	check_collectible(data, data->map->pl_p.x - 1, data->map->pl_p.y);
	move_player(data, data->map->pl_p.x - 1, data->map->pl_p.y);
}

void	move_right(t_expose_data *data)
{
	if (!should_move(data, data->map->pl_p.x + 1, data->map->pl_p.y))
		return ;
	if (data->map->cells[data->map->pl_p.y][data->map->pl_p.x + 1]->state
		== CELL_EXIT_UNLOCKED)
	{
		put_victory_message(data);
		return ;
	}
	if (data->map->cells[data->map->pl_p.y][data->map->pl_p.x + 1]->state
		== CELL_DANGER)
	{
		put_defeat_message(data);
		return ;
	}
	check_collectible(data, data->map->pl_p.x + 1, data->map->pl_p.y);
	move_player(data, data->map->pl_p.x + 1, data->map->pl_p.y);
}

int	handle_x(void *param)
{
	t_expose_data	*data;

	data = (t_expose_data *)param;
	free_lib(data);
	return (0);
}
