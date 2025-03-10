/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:42:04 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 11:03:31 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "stdio.h"
#include <fcntl.h>
#include <unistd.h>

int	map_val(char **ar)
{
	if (!ar)
	{
		write(1, "Error\nEmpty file\n", 18);
		return (0);
	}
	if (!check_rectangular(ar))
		return (0);
	if (!check_allowed_symbols(ar))
		return (0);
	if (!check_player_or_exit_count(ar, 'P') || !check_player_or_exit_count(ar,
			'E'))
		return (0);
	if (!check_borders(ar) || !check_sides(ar))
		return (0);
	if (!check_collectibles(ar))
		return (0);
	if (!check_ways(ar))
		return (0);
	return (1);
}
