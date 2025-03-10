/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:54:10 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 18:50:42 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*read_file_contents(char *file_name)
{
	int			file;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;
	static char	*str;

	str = NULL;
	file = open(file_name, O_RDONLY);
	if (file == -1)
	{
		write(1, "Error\nError opening file\n", 25);
		return (str);
	}
	bytes = read(file, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		ft_strjoin(&str, buffer);
		bytes = read(file, buffer, BUFFER_SIZE);
	}
	close(file);
	return (str);
}
