/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:53:26 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 14:39:33 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

t_instances	*initialize_burning_ship_instances(void)
{
	t_instances	*instances;

	instances = malloc(sizeof(t_instances));
	if (!instances)
		return (NULL);
	instances->mlx = mlx_init(WIDTH, HEIGHT, "Burning Ship", false);
	instances->img = mlx_new_image(instances->mlx, WIDTH, HEIGHT);
	instances->point = init_point(0, 0);
	instances->axe = init_axe(-2, -2, 2, 2);
	instances->mouse = init_mouse();
	instances->max_iter = 100.0;
	instances->ft_color = &ft_color_1;
	instances->color_alter = 0.0;
	instances->bool_instr = 0;
	instances->bool_iter = 1;
	return (instances);
}

void	burning_ship(void)
{
	t_instances	*instances;

	instances = initialize_burning_ship_instances();
	draw_burning_ship(instances);
	mlx_image_to_window(instances->mlx, instances->img, 0, 0);
	add_burning_ship_hooks(instances);
	mlx_loop(instances->mlx);
	terminate(instances);
}
