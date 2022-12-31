/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:35:40 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 16:14:52 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

double	get_width_of_axe(t_axe	*axe)
{
	return (axe->width_axe);
}

double	get_height_of_axe(t_axe	*axe)
{
	return (axe->height_axe);
}

double	get_x_scaled_to_point(int x, t_instances *instances)
{
	t_axe	*axe;

	axe = instances->axe;
	return (axe->width_axe * ((double)x - WIDTH / 2) / WIDTH + axe->x_offset);
}

double	get_y_scaled_to_point(int y, t_instances *instances)
{
	t_axe	*axe;

	axe = instances->axe;
	return (axe->height_axe * ((double)y - HEIGHT / 2) / HEIGHT
		+ axe->y_offset);
}

void	get_mouse_coordinates(t_instances *instances)
{
	int		x_pix;
	int		y_pix;
	t_mouse	*mouse;
	double	width_of_axe;
	double	height_of_axe;

	mouse = instances->mouse;
	mlx_get_mouse_pos(instances->mlx, &x_pix, &y_pix);
	width_of_axe = get_width_of_axe(instances->axe);
	height_of_axe = get_height_of_axe(instances->axe);
	mouse->x = instances->axe->start_x + x_pix * (width_of_axe) / WIDTH;
	mouse->y = instances->axe->start_y + y_pix * (height_of_axe) / HEIGHT;
}
