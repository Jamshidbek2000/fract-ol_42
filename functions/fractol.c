/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:17:47 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 18:59:31 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_frac.h"

void	input_error(void)
{
	write(2, "\n\n\t\t\tWRONG INPUT\n\n", 18);
	write(2, "Templates : \n\n", 14);
	write(1, "$ ./fractol mandelbrot\n", 23);
	write(1, "$ ./fractol burning_ship\n", 25);
	write(1, "$ ./fractol julia (float_number_y) (float_number_x)\n\n", 53);
	write(1, "e.g:", 4);
	write(1, "\t$ ./fractol mandelbrot\n", 24);
	write(1, "\t$ ./fractol burning_ship\n", 26);
	write(1, "\t$ ./fractol julia 0.0 -1.476\n", 30);
	write(1, "\nsome good examples for julia\n", 30);
	write(1, "0.0 , -1.476\n0.7449, -0.1226\n0.05, 0.34\n0.11, -0.75", 52);
	write(1, "\nAvailable sets: mandelbrot, julia, burning_ship\n\n", 50);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		to_lower_case(argv[1]);
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
			mandelbrot();
		else if (ft_strncmp(argv[1], "burning_ship", 12) == 0)
			burning_ship();
		else
			input_error();
	}
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0
		&& ft_is_float(argv[2]) && ft_is_float(argv[3]))
		julia(ft_atof(argv[2]), ft_atof(argv[3]));
	else
		input_error();
	leak_check();
	return (0);
}
