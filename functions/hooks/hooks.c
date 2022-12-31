/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:37:35 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 18:40:23 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

void	common_keyhooks(void *param)
{
	t_instances	*instances;

	instances = (t_instances *)param;
	if (mlx_is_key_down(instances->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(instances->mlx);
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_I))
		instances->bool_instr = -1;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_O))
		instances->bool_instr = 1;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_Y))
		instances->bool_iter = 1;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_U))
		instances->bool_iter = -1;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_KP_ADD))
		instances->max_iter++;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_KP_SUBTRACT))
		instances->max_iter--;
}

void	color_keyhooks(void *param)
{
	t_instances	*instances;

	instances = (t_instances *)param;
	if (mlx_is_key_down(instances->mlx, MLX_KEY_P))
		instances->color_alter = -0.1;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_S))
		instances->color_alter = 0.1;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_1))
		instances->ft_color = &ft_color_1;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_2))
		instances->ft_color = &ft_color_2;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_3))
		instances->ft_color = &ft_color_3;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_4))
		instances->ft_color = &ft_color_4;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_5))
		instances->ft_color = &ft_color_5;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_6))
		instances->ft_color = &ft_color_6;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_7))
		instances->ft_color = &ft_color_7;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_8))
		instances->ft_color = &ft_color_8;
	else if (mlx_is_key_down(instances->mlx, MLX_KEY_9))
		instances->ft_color = &ft_color_9;
}

void	add_mandelbrot_hooks(t_instances *instances)
{
	mlx_scroll_hook(instances->mlx, &scrollhook, instances);
	mlx_loop_hook(instances->mlx, &mandelbrot_keyhook, instances);
	mlx_loop_hook(instances->mlx, &common_keyhooks, instances);
	mlx_loop_hook(instances->mlx, &color_keyhooks, instances);
}

void	add_julia_hooks(t_instances *instances)
{
	mlx_scroll_hook(instances->mlx, &scrollhook, instances);
	mlx_loop_hook(instances->mlx, &julia_keyhook, instances);
	mlx_loop_hook(instances->mlx, &common_keyhooks, instances);
	mlx_loop_hook(instances->mlx, &color_keyhooks, instances);
}

void	add_burning_ship_hooks(t_instances *instances)
{
	mlx_scroll_hook(instances->mlx, &scrollhook, instances);
	mlx_loop_hook(instances->mlx, &burning_ship_keyhook, instances);
	mlx_loop_hook(instances->mlx, &common_keyhooks, instances);
	mlx_loop_hook(instances->mlx, &color_keyhooks, instances);
}
