/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mborsuk <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 10:04:25 by mborsuk       #+#    #+#                 */
/*   Updated: 2025/03/10 14:24:42 by mborsuk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_split.h"
#include "lib/ft_strjoin.h"
// #include "../minilibx/mlx.h"
#include "minilibx/mlx.h"
#include "src/display_map.h"
#include "src/free_functions.h"
#include "src/map.h"
#include "src/maps_utils.h"
#include "src/movement.h"
#include "src/utils_2.h"
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MALLOC_ERROR 1

int	movements_b(int keycode, void *param)
{
	t_expose_data	*data;

	data = (t_expose_data *)param;
	if (keycode == KEY_W)
		move_up(data);
	else if (keycode == KEY_A)
		move_left(data);
	else if (keycode == KEY_S)
		move_down(data);
	else if (keycode == KEY_D)
		move_right(data);
	return (0);
}

int	closef(int keycode, void *param)
{
	t_expose_data	*data;

	data = (t_expose_data *)param;
	if (keycode == 65307)
		free_lib(data);
	return (0);
}

void	init_hooks(t_expose_data *expose_data)
{
	mlx_key_hook(expose_data->w_p, movements_b, expose_data);
	mlx_hook(expose_data->w_p, 2, 1L << 0, closef, expose_data);
	mlx_hook(expose_data->w_p, 33, 1L << 17, handle_x, expose_data);
	mlx_expose_hook(expose_data->w_p, expose_callback, expose_data);
}

void	expose(t_expose_data *expose_data)
{
	init_image_pointers(expose_data->m_p);
	draw_map(expose_data);
	init_hooks(expose_data);
	mlx_loop(expose_data->m_p);
	free_lib(expose_data);
}

int	main(int argc, char *argv[])
{
	t_expose_data	*e_x;
	t_map			*map;

	if (argc == 2)
	{
		map = parse_map(argv[1]);
		if (!map)
			return (1);
		e_x = (t_expose_data *)malloc(sizeof(t_expose_data));
		if (!e_x)
			return (1);
		e_x->map = map;
		e_x->m_p = mlx_init();
		if (e_x->m_p == NULL)
			perror_exit("Failed to initialize MinilibX");
		e_x->w_p = mlx_new_window(e_x->m_p, CELL_W * e_x->map->x,
				CELL_H * e_x->map->y, "Game");
		invalid_size(e_x);
		if (e_x->w_p == NULL)
			destroy_window(e_x->m_p);
		expose(e_x);
	}
	else
		perror_exit("Error\nWrong number of arguments.");
	return (0);
}
