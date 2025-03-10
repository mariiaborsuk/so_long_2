/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:39:49 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 16:15:00 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../utils_2.h"

int	check_rectangular(char **ar)
{
	int	i;
	int	len_1;
	int	len_2;

	i = 0;
	while (ar[i] && ar[i + 1])
	{
		len_1 = get_len(ar[i]);
		len_2 = get_len(ar[i + 1]);
		if (len_1 != len_2)
		{
			write(1, "Error\nNo rectangular\n", 22);
			return (0);
		}
		i++;
	}
	return (1);
}
