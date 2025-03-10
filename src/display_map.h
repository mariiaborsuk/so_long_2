/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:43:43 by mborsuk       #+  #+#    #+#             */
/*   Updated: 2025/03/01 12:06:43 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_MAP_H
# define DISPLAY_MAP_H
# include "map.h"

void	draw_map(t_expose_data *data);

void	draw_moves(t_map *map);

void	draw_cell(t_expose_data *data, int x, int y);

#endif
