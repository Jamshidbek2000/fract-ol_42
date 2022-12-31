/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:26:22 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 10:03:59 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

int	get_nb_of_julia_iter(double y, double x, t_instances *instances);

void	draw_julia(t_instances *instances)
{
	int		index_width;
	int		index_height;
	int		iters;
	double	x_scaled;
	double	y_scaled;

	index_height = 0;
	change_color(instances);
	while (index_height < HEIGHT)
	{
		index_width = 0;
		while (index_width < WIDTH)
		{
			x_scaled = get_x_scaled_to_point(index_width, instances);
			y_scaled = (-1) * get_y_scaled_to_point(index_height, instances);
			iters = get_nb_of_julia_iter(y_scaled, x_scaled,
					instances) + (int)instances->color_alter;
			color_pixel_by_iter(index_height, index_width, iters, instances);
			index_width++;
		}
		index_height++;
	}
	put_instructions_on_screen(instances);
}

int	get_nb_of_julia_iter(double y, double x, t_instances *instances)
{
	double	real;
	double	imaginary;
	int		iter;
	double	next_real;
	t_point	*point;

	point = instances->point;
	iter = 0;
	real = x;
	imaginary = y;
	while ((double)iter < instances->max_iter
		&& real * real + imaginary * imaginary < 4.0)
	{
		next_real = real * real - imaginary * imaginary;
		imaginary = 2 * real * imaginary + point->y;
		real = next_real + point->x;
		iter++;
	}
	return (iter);
}
