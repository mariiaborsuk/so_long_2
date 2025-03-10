/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:03:52 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 18:35:10 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./validation/validation.h"
#include "map.h"
#include <stdio.h>
#include <unistd.h>

int	get_ar_len(char **ar)
{
	int	i;

	i = 0;
	if (!ar)
		return (0);
	while (ar[i])
		i++;
	return (i);
}

int	get_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	perror_exit(char *message)
{
	write(1, message, get_len(message));
	exit(EXIT_FAILURE);
}
