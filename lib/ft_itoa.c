/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:30:24 by mborsuk       #+  #+#    #+#             */
/*   Updated: 2025/03/01 10:30:49 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strjoin.h"
#include <malloc.h>
#include <stdlib.h>

int	find_len(unsigned int n)
{
	unsigned int	temp;
	unsigned int	len;

	len = 0;
	temp = n;
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	return (len);
}

char	*ft_itoa(unsigned int n)
{
	unsigned int	len;
	char			*str;

	if (n == 0)
		len = 1;
	else
		len = find_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
