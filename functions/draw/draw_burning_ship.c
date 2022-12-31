/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:54:39 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/30 10:19:24 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

int	get_nb_of_burning_ship_iter(double y, double x, int max_iter);

void	draw_burning_ship(t_instances *instances)
{
	int		index_height;
	int		index_width;
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
			y_scaled = get_y_scaled_to_point(index_height, instances);
			iters = get_nb_of_burning_ship_iter(y_scaled, x_scaled,
					instances->max_iter) + (int)instances->color_alter;
			color_pixel_by_iter(index_height, index_width, iters, instances);
			index_width++;
		}
		index_height++;
	}
	put_instructions_on_screen(instances);
}

int	get_nb_of_burning_ship_iter(double y, double x, int max_iter)
{
	double	real;
	double	imaginary;
	int		iter;
	double	next_real;

	iter = 0;
	real = x;
	imaginary = y;
	while ((double)iter < max_iter && real * real + imaginary * imaginary < 4.0)
	{
		next_real = real * real - imaginary * imaginary + x;
		imaginary = fabs(2 * real * imaginary) + y;
		real = next_real;
		iter++;
	}
	return (iter);
}
