/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:21:00 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/30 17:51:53 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

uint32_t	ft_color_1(int iter)
{
	int	n;

	n = iter % 10;
	if (n == 0)
		return (get_rgba(255, 0, 0, 215));
	else if (n == 1)
		return (get_rgba(25, 0, 0, 215));
	else if (n == 2)
		return (get_rgba(50, 0, 0, 215));
	else if (n == 3)
		return (get_rgba(75, 0, 0, 215));
	else if (n == 4)
		return (get_rgba(100, 0, 0, 215));
	else if (n == 5)
		return (get_rgba(125, 0, 0, 215));
	else if (n == 6)
		return (get_rgba(150, 0, 0, 215));
	else if (n == 7)
		return (get_rgba(175, 0, 0, 215));
	else if (n == 8)
		return (get_rgba(200, 0, 0, 215));
	else if (n == 9)
		return (get_rgba(225, 0, 0, 215));
	return (get_rgba(255, 255, 255, 215));
}

uint32_t	ft_color_2(int iter)
{
	int	n;

	n = iter % 10;
	if (n == 0)
		return (get_rgba(0, 255, 0, 255));
	else if (n == 1)
		return (get_rgba(0, 25, 0, 255));
	else if (n == 2)
		return (get_rgba(0, 50, 0, 255));
	else if (n == 3)
		return (get_rgba(0, 75, 0, 255));
	else if (n == 4)
		return (get_rgba(0, 100, 0, 255));
	else if (n == 5)
		return (get_rgba(0, 125, 0, 255));
	else if (n == 6)
		return (get_rgba(0, 150, 0, 255));
	else if (n == 7)
		return (get_rgba(0, 175, 0, 255));
	else if (n == 8)
		return (get_rgba(0, 200, 0, 255));
	else if (n == 9)
		return (get_rgba(0, 225, 0, 255));
	return (get_rgba(255, 255, 255, 255));
}

uint32_t	ft_color_3(int iter)
{
	int	n;

	n = iter % 10;
	if (n == 0)
		return (get_rgba(0, 0, 255, 255));
	else if (n == 1)
		return (get_rgba(0, 0, 25, 255));
	else if (n == 2)
		return (get_rgba(0, 0, 50, 255));
	else if (n == 3)
		return (get_rgba(0, 0, 75, 255));
	else if (n == 4)
		return (get_rgba(0, 0, 100, 255));
	else if (n == 5)
		return (get_rgba(0, 0, 125, 255));
	else if (n == 6)
		return (get_rgba(0, 0, 150, 255));
	else if (n == 7)
		return (get_rgba(0, 0, 175, 255));
	else if (n == 8)
		return (get_rgba(0, 0, 200, 255));
	else if (n == 9)
		return (get_rgba(0, 0, 225, 255));
	return (get_rgba(255, 255, 255, 255));
}

uint32_t	ft_color_4(int iter)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = (int)(255.0 * sin(2 * M_PI * iter)) % 256;
	g = (int)(255.0 * sin(2 * M_PI * iter + 2 * M_PI / 3)) % 256;
	b = (int)(255.0 * sin(2 * M_PI * iter + 4 * M_PI / 3)) % 256;
	a = (iter * 5) % 256;
	return (get_rgba(r, g, b, a));
}

uint32_t	ft_color_5(int iter)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = (int)(255.0 * sin(2 * M_PI * iter / 256.0));
	g = (int)(255.0 * cos(2 * M_PI * iter / 256.0));
	b = (int)(255.0 * sin(2 * M_PI * iter / 256.0 + M_PI / 2));
	a = (int)(255.0 * cos(2 * M_PI * iter / 256.0 + M_PI));
	return (get_rgba(r, g, b, a));
}
