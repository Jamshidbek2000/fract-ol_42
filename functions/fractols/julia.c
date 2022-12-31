/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:13:43 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 14:39:25 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

t_instances	*initialize_julia_instances(double y, double x)
{
	t_instances	*instances;

	instances = malloc(sizeof(t_instances));
	if (!instances)
		return (NULL);
	instances->mlx = mlx_init(WIDTH, HEIGHT, "Julia", false);
	instances->img = mlx_new_image(instances->mlx, WIDTH, HEIGHT);
	instances->point = init_point(y, x);
	instances->axe = init_axe(-2, -2, 2, 2);
	instances->mouse = init_mouse();
	instances->max_iter = 100.0;
	instances->ft_color = &ft_color_1;
	instances->color_alter = 0.0;
	instances->bool_instr = 0;
	instances->bool_iter = 1;
	return (instances);
}

void	julia(double y, double x)
{
	t_instances	*instances;

	instances = initialize_julia_instances(y, x);
	draw_julia(instances);
	mlx_image_to_window(instances->mlx, instances->img, 0, 0);
	add_julia_hooks(instances);
	mlx_loop(instances->mlx);
	terminate(instances);
}
