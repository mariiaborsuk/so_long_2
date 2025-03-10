/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:38:10 by mborsuk       #+  #+#    #+#             */
/*   Updated: 2025/03/01 12:06:23 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRJOIN_H
# define FT_STRJOIN_H

# include <stddef.h>

char	*ft_strchr(const char *s, const char c);

void	ft_strjoin(char **s1, const char *s2);

size_t	ft_strlen(const char *str);
#endif
