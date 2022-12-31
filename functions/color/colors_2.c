/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:06:30 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/30 17:53:08 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/lib_frac.h"

uint32_t	ft_color_6(int iter)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = (iter * 2) % 256;
	g = (iter * 3) % 256;
	b = (iter * 4) % 256;
	a = (iter * 5) % 256;
	return (get_rgba(r, g, b, a));
}

uint32_t	ft_color_7(int iter)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = ((iter * 5) + iter / 2) % 255;
	g = ((iter * 7) + iter / 3) % 255;
	b = ((iter * 9) + iter / 4) % 255;
	a = ((iter * 11) + iter / 5) % 255;
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	ft_color_8_2(int n)
{
	if (n == 10)
		return (get_rgba(241, 233, 191, 255));
	else if (n == 11)
		return (get_rgba(248, 201, 95, 255));
	else if (n == 12)
		return (get_rgba(255, 170, 0, 255));
	else if (n == 13)
		return (get_rgba(204, 128, 0, 255));
	else if (n == 14)
		return (get_rgba(153, 87, 0, 255));
	return (get_rgba(106, 52, 3, 255));
}

uint32_t	ft_color_8(int iter)
{
	int	n;

	n = iter % 16;
	if (n == 0)
		return (get_rgba(66, 30, 15, 255));
	else if (n == 1)
		return (get_rgba(25, 7, 26, 255));
	else if (n == 2)
		return (get_rgba(9, 1, 47, 255));
	else if (n == 3)
		return (get_rgba(4, 4, 73, 255));
	else if (n == 4)
		return (get_rgba(0, 7, 100, 255));
	else if (n == 5)
		return (get_rgba(12, 44, 138, 255));
	else if (n == 6)
		return (get_rgba(24, 82, 177, 255));
	else if (n == 7)
		return (get_rgba(57, 125, 209, 255));
	else if (n == 8)
		return (get_rgba(134, 181, 229, 255));
	else if (n == 9)
		return (get_rgba(211, 236, 248, 255));
	return (ft_color_8_2(n));
}

uint32_t	ft_color_9(int iter)
{
	int	n;

	n = iter % 16;
	if (n == 0)
		return (get_rgba(3, 50, 112, 255));
	else if (n == 1)
		return (get_rgba(19, 104, 170, 255));
	else if (n == 2)
		return (get_rgba(64, 145, 201, 255));
	else if (n == 3)
		return (get_rgba(157, 206, 226, 255));
	else if (n == 4)
		return (get_rgba(254, 223, 212, 255));
	else if (n == 5)
		return (get_rgba(242, 148, 121, 255));
	else if (n == 6)
		return (get_rgba(242, 106, 79, 255));
	else if (n == 7)
		return (get_rgba(239, 60, 45, 255));
	else if (n == 8)
		return (get_rgba(203, 27, 22, 255));
	return (get_rgba(101, 1, 12, 255));
}
