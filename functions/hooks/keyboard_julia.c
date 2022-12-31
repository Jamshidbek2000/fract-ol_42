/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:53:09 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/30 10:27:48 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

void	restart_julia(t_instances *instances)
{
	t_axe	*axe;

	axe = instances->axe;
	axe->end_x = 2.0;
	axe->start_x = -2.0;
	axe->end_y = 2.0;
	axe->start_y = -2.0;
	axe->y_offset = 0.0;
	axe->x_offset = 0.0;
	axe->width_axe = axe->end_x - axe->start_x;
	axe->height_axe = axe->end_y - axe->start_y;
	instances->max_iter = 80.0;
}

void	get_point_coordinates(t_instances *instances)
{
	int		x_pix;
	int		y_pix;
	t_point	*point;
	double	width_of_axe;
	double	height_of_axe;

	point = instances->point;
	mlx_get_mouse_pos(instances->mlx, &x_pix, &y_pix);
	width_of_axe = get_width_of_axe(instances->axe);
	height_of_axe = get_height_of_axe(instances->axe);
	point->x = instances->axe->start_x + x_pix * (width_of_axe) / WIDTH;
	point->y = instances->axe->start_y + y_pix * (height_of_axe) / HEIGHT;
}

void	julia_keyhook(void *param)
{
	t_instances	*instances;

	instances = (t_instances *)param;
	if (mlx_is_key_down(instances->mlx, MLX_KEY_RIGHT))
		move_real(instances, instances->axe->width_axe / 20);
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_LEFT))
		move_real(instances, (-1) * instances->axe->width_axe / 20);
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_UP))
		move_imaginary(instances, (-1) * instances->axe->height_axe / 20);
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_DOWN))
		move_imaginary(instances, instances->axe->height_axe / 20);
	draw_julia(instances);
	if (mlx_is_key_down(instances->mlx, MLX_KEY_R))
		restart_julia(instances);
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_M))
		draw_mandelbrot(instances);
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_B))
		draw_burning_ship(instances);
	if (mlx_is_mouse_down(instances->mlx, MLX_MOUSE_BUTTON_LEFT))
		get_point_coordinates(instances);
}
