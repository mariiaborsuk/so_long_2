/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mborsuk <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/05 10:03:25 by mborsuk       #+#    #+#                 */
/*   Updated: 2025/03/05 10:07:05 by mborsuk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# include "free_functions.h"

enum	e_movement_keys
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
};

void	move_up(t_expose_data *data);

void	move_down(t_expose_data *data);

void	move_left(t_expose_data *data);

void	move_right(t_expose_data *data);

int		handle_x(void *param);

#endif
