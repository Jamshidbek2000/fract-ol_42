/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:20:18 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/30 16:27:33 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

t_point	*init_point(double y, double x)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->y = y;
	point->x = x;
	return (point);
}

t_axe	*init_axe(double start_y, double start_x, double end_y, double end_x)
{
	t_axe	*axe;

	axe = malloc(sizeof(t_axe));
	if (!axe)
		return (NULL);
	axe->start_y = start_y;
	axe->start_x = start_x;
	axe->end_y = end_y;
	axe->end_x = end_x;
	axe->x_offset = 0;
	axe->y_offset = 0;
	axe->height_axe = axe->end_y - axe->start_y;
	axe->width_axe = axe->end_x - axe->start_x;
	return (axe);
}

t_mouse	*init_mouse(void)
{
	t_mouse	*mouse;

	mouse = malloc(sizeof(t_mouse));
	if (!mouse)
		return (NULL);
	return (mouse);
}
