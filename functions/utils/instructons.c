/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:12:40 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 18:14:37 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

void	print_iter(t_instances*instances)
{
	char				*str;
	char				*iter;
	static mlx_image_t	*img;

	mlx_delete_image(instances->mlx, img);
	if (instances->bool_iter < 0.0)
		return ;
	str = NULL;
	str = ft_strjoin_free_1(str, "Iterations : ");
	iter = ft_itoa((int)(instances->max_iter));
	str = ft_strjoin_free_1(str, iter);
	img = mlx_put_string(instances->mlx, str, WIDTH - 200, HEIGHT - 50);
	free(iter);
	free(str);
}

void	print_instruction_1(mlx_t	*mlx, int bool_instr)
{
	static mlx_image_t	*tmp;
	static mlx_image_t	*arrows;
	static mlx_image_t	*zoom;
	static mlx_image_t	*reset;
	static mlx_image_t	*color;

	mlx_delete_image(mlx, tmp);
	mlx_delete_image(mlx, arrows);
	mlx_delete_image(mlx, zoom);
	mlx_delete_image(mlx, reset);
	mlx_delete_image(mlx, color);
	if (bool_instr < 0)
		return ;
	tmp = mlx_put_string(mlx, "  ", 20, 20);
	arrows = mlx_put_string(mlx, "Move with arrows", 20, 20);
	zoom = mlx_put_string(mlx, "Zoom IN/OUT with mouse wheel", 20, 40);
	reset = mlx_put_string(mlx, "Reset : R", 20, 60);
	color = mlx_put_string(mlx, "Change colors : 1-9", 20, 80);
}

void	print_instruction_2(mlx_t	*mlx, int bool_instr)
{
	static mlx_image_t	*color_on;
	static mlx_image_t	*color_off;
	static mlx_image_t	*mandelbrot;
	static mlx_image_t	*burning_ship;
	static mlx_image_t	*iter_incr;

	mlx_delete_image(mlx, color_off);
	mlx_delete_image(mlx, color_on);
	mlx_delete_image(mlx, mandelbrot);
	mlx_delete_image(mlx, burning_ship);
	mlx_delete_image(mlx, iter_incr);
	if (bool_instr < 0)
		return ;
	color_on = mlx_put_string(mlx, "Start color play : S", 20, 100);
	color_off = mlx_put_string(mlx, "Pause color play : P", 20, 120);
	mandelbrot = mlx_put_string(mlx, "Show Mandelbrot : M", 20, 140);
	burning_ship = mlx_put_string(mlx, "Show Burning Ship : B", 20, 160);
	iter_incr = mlx_put_string(mlx, "Increase precision (iterations) : +",
			20, 180);
}

void	print_instruction_3(mlx_t	*mlx, int bool_instr)
{
	static mlx_image_t	*iter_decr;
	static mlx_image_t	*esq;
	static mlx_image_t	*julia;
	static mlx_image_t	*instr;
	static mlx_image_t	*iter;

	mlx_delete_image(mlx, iter_decr);
	mlx_delete_image(mlx, esq);
	mlx_delete_image(mlx, julia);
	mlx_delete_image(mlx, instr);
	mlx_delete_image(mlx, iter);
	if (bool_instr < 0)
		return ;
	iter_decr = mlx_put_string(mlx, "Decrease precision (iterations) : -",
			20, 200);
	esq = mlx_put_string(mlx, "Close window: Esc", 20, 220);
	julia = mlx_put_string(mlx, "Julia move: Left mouse click", 20, 240);
	instr = mlx_put_string(mlx, "Switch ON/OFF instructions : I/O", 20, 260);
	iter = mlx_put_string(mlx, "Switch ON/OFF iteration count : Y/U", 20, 280);
}

void	put_instructions_on_screen(t_instances*instances)
{
	print_iter(instances);
	if (instances->bool_instr > 0)
	{
		print_instruction_1(instances->mlx, instances->bool_instr);
		print_instruction_2(instances->mlx, instances->bool_instr);
		print_instruction_3(instances->mlx, instances->bool_instr);
	}
}
