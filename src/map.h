/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:00:37 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 18:48:52 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../lib/ft_itoa.h"
# include "../lib/ft_split.h"
# include "../lib/ft_strjoin.h"
# include "minilibx/mlx.h"
# include "map.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 50
# define CELL_W 100
# define CELL_H 100

typedef struct t_cell
{
	char			value;
	char			state;
	int				x;
	int				y;
}					t_cell;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_data;

typedef struct s_pl_p
{
	unsigned int	x;
	unsigned int	y;
}					t_pl_p;

typedef struct s_exit_pos
{
	unsigned int	x;
	unsigned int	y;
}					t_exit_pos;
typedef struct s_danger
{
	unsigned int	x;
	unsigned int	y;

}					t_danger;
typedef struct s_map
{
	unsigned int	x;
	unsigned int	y;
	t_pl_p			pl_p;
	t_cell			***cells;
	t_exit_pos		exit_pos;
	t_danger		danger;
	unsigned int	collectibles;
	unsigned char	is_victory;
	unsigned int	moves;
	unsigned char	lost;

}					t_map;

enum				e_map_cells
{
	CELL_EMPTY = 48,
	CELL_WALL = 49,
	CELL_PLAYER = 80,
	CELL_COLLECTIBLE = 67,
	CELL_EXIT_LOCKED = 69,
	CELL_EXIT_UNLOCKED = 85,
	CELL_DANGER = 68
};
typedef struct s_expose_data
{
	t_map			*map;
	void			*m_p;
	void			*w_p;
}					t_expose_data;

typedef struct s_cleanup_data
{
	void			*mlx;
	void			*win;
	t_map			*map;
}					t_cleanup_data;

int					map_val(char **ar);

int					get_ar_len(char **ar);

t_map				*parse_map(char *file_name);
void				expose(t_expose_data *expose_data);

char				*read_file_contents(char *file_name);
#endif
