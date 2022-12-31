/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:34:09 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/30 16:24:57 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	change_color(t_instances *instances)
{
	if (instances->color_alter > 0)
	{
		instances->color_alter += 0.06;
		if (instances->color_alter > 16.0)
			instances->color_alter -= 16.0;
	}
}

uint32_t	get_color_by_iter(int iter, t_instances *instances)
{
	if (iter == (int)instances->max_iter)
		return (get_rgba(0, 0, 0, 255));
	return (instances->ft_color(iter));
}

void	color_pixel_by_iter(int y, int x, int iter, t_instances *instances)
{
	uint32_t	color;

	color = get_color_by_iter(iter, instances);
	mlx_put_pixel(instances->img, x, y, color);
}
