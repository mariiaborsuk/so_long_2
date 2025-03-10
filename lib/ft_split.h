/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mborsuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:31:04 by mborsuk           #+#    #+#             */
/*   Updated: 2025/03/09 18:33:29 by mborsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

typedef struct t_split
{
	char	**ar;
	int		line_count;

}			t_split;
void		ft_split(char const *s, char c, t_split *split);

#endif
