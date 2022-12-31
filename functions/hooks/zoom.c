/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:40:31 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 18:43:57 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_instances	*instances;

	(void) xdelta;
	instances = (t_instances *)param;
	if (ydelta > 0.0)
		zoom_in(instances);
	else if (ydelta < 0.0)
		zoom_out(instances);
}

void	multiply_axe_val_by(t_axe *axe, double mult)
{
	axe->start_x *= mult;
	axe->end_x *= mult;
	axe->start_y *= mult;
	axe->end_y *= mult;
	axe->width_axe = (axe->end_x - axe->start_x);
	axe->height_axe = (axe->end_y - axe->start_y);
}

void	set_axe_offset(t_instances *instances)
{
	t_axe	*axe;
	t_mouse	*mouse;
	double	prev_mouse_x;
	double	prev_mouse_y;

	axe = instances->axe;
	mouse = instances->mouse;
	prev_mouse_x = mouse->x;
	prev_mouse_y = mouse->y;
	get_mouse_coordinates(instances);
	axe->x_offset += prev_mouse_x - mouse->x;
	axe->y_offset += prev_mouse_y - mouse->y;
}

void	zoom_in(t_instances *instances)
{
	double	zoom_val;

	zoom_val = 0.7;
	instances->max_iter += 1.2;
	get_mouse_coordinates(instances);
	multiply_axe_val_by(instances->axe, zoom_val);
	set_axe_offset(instances);
}

void	zoom_out(t_instances *instances)
{
	double	zoom_val;

	zoom_val = 1.3;
	instances->max_iter -= 1.2;
	get_mouse_coordinates(instances);
	multiply_axe_val_by(instances->axe, zoom_val);
	set_axe_offset(instances);
}
