/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maps_utils.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mborsuk <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/01 10:47:05 by mborsuk       #+#    #+#                 */
/*   Updated: 2025/03/10 14:28:18 by mborsuk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_UTILS_H
# define MAPS_UTILS_H
# include "free_functions.h"

typedef struct s_image_pointers
{
	void			*image_wall;
	void			*image_space;
	void			*image_player;
	void			*image_collectible;
	void			*image_locked_exit;
	void			*image_unlocked;
	void			*danger;
}					t_image_pointers;

void				free_image_pointers(void *m_p);

void				init_image_pointers(void *m_p);

t_image_pointers	*get_image_pointers(void);

int					expose_callback(void *param);
void				invalid_size(t_expose_data *expose_data);

#endif
