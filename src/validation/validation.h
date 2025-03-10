/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:42:21 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 18:36:18 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

typedef struct s_c
{
	int	start_x;
	int	start_y;
}		t_c;

typedef struct s_all_coordinates
{
	t_c	player_pos;
	t_c	exit_pos;
	t_c	*collectible_pos;
}		t_all_coordinates;

int		check_borders(char **ar);

int		check_sides(char **ar);

int		check_collectibles(char **ar);

int		check_file_extension(char *filenane);

int		check_player_or_exit_count(char **ar, char c);

int		check_rectangular(char **ar);

int		check_allowed_symbols(char **ar);

void	modify_ar(char **ar, int start_y, int start_x);

t_c		*get_collectible_coordinates(char **array);

int		map_val(char **ar);

int		check_ways(char **ar);

char	**copy_array(char **array, int size);

int		check_if_position_is_accessible(char **array, t_c *position);

int		check_all_positions(char **array, t_c *player_position,
			t_c *exit_position, t_c *collectible_positions);

void	init_coords(t_c *coords);

int		check_file_extension(char *filename);
#endif
