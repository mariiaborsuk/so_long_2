/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:48:49 by mborsuk       #+  #+#    #+#             */
/*   Updated: 2025/03/01 12:10:51 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_UTILS_H
# define MOVEMENT_UTILS_H

void	put_victory_message(t_expose_data *data);

void	put_defeat_message(t_expose_data *data);

int		should_move(t_expose_data *data, int x, int y);

void	check_collectible(t_expose_data *data, int x, int y);

void	move_player(t_expose_data *data, int x, int y);
#endif
