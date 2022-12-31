/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:04:06 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 14:42:46 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

t_instances	*initialize_instances(void)
{
	t_instances	*instances;

	instances = malloc(sizeof(t_instances));
	if (!instances)
		return (NULL);
	instances->mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", false);
	instances->img = mlx_new_image(instances->mlx, WIDTH, HEIGHT);
	instances->point = init_point(0, 0);
	instances->axe = init_axe(-2, -2, 2, 2);
	instances->mouse = init_mouse();
	instances->max_iter = 100.0;
	instances->ft_color = &ft_color_1;
	instances->color_alter = 0.0;
	instances->bool_instr = 1;
	instances->bool_iter = 1;
	return (instances);
}

void	mandelbrot(void)
{
	t_instances	*instances;

	instances = initialize_instances();
	draw_mandelbrot(instances);
	mlx_image_to_window(instances->mlx, instances->img, 0, 0);
	add_mandelbrot_hooks(instances);
	mlx_loop(instances->mlx);
	terminate(instances);
}
