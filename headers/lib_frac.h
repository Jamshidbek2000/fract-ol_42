/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_frac.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:00:27 by jergashe          #+#    #+#             */
/*   Updated: 2022/12/31 19:46:26 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FRAC_H
# define LIB_FRAC_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <memory.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft_42/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 400

typedef struct s_mouse
{
	double		x;
	double		y;
}				t_mouse;

typedef struct s_point
{
	double		y;
	double		x;
}				t_point;

typedef struct s_axe
{
	double		start_y;
	double		end_y;
	double		start_x;
	double		end_x;
	double		width_axe;
	double		height_axe;
	double		x_offset;
	double		y_offset;
}				t_axe;

typedef struct s_instances
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_point		*point;
	t_axe		*axe;
	t_mouse		*mouse;
	double		max_iter;
	int			bool_instr;
	int			bool_iter;
	uint32_t	(*ft_color)(int iter);
	double		color_alter;
}				t_instances;

// MANDELBROT.C
void			mandelbrot(void);

// JULIA.C
void			julia(double y, double x);

// BURNING_SHIP.C
void			burning_ship(void);

// DRAW_MANDELBROT.C
void			draw_mandelbrot(t_instances *instances);

// DRAW_JULIA.C
void			draw_julia(t_instances *instances);

// DRAW_BURNING_SHIP.C
void			draw_burning_ship(t_instances *instances);

// HOOKS.C
void			add_mandelbrot_hooks(t_instances *instances);
void			add_julia_hooks(t_instances *instances);
void			add_burning_ship_hooks(t_instances *instances);
void			common_keyhooks(void *param);

// SCROLL_HOOK.C
void			scrollhook(double xdelta, double ydelta,
					void *param);

// KEYBOARD_MANDELBROT.C
void			mandelbrot_keyhook(void *param);

// KEYBOARD_JULIA.C
void			julia_keyhook(void *param);

// KEYBOARD_.C
void			burning_ship_keyhook(void *param);

// ZOOM.C
void			multiply_axe_val_by(t_axe *axe, double mult);
void			set_axe_offset(t_instances *instances);
void			zoom_in(t_instances *instances);
void			zoom_out(t_instances *instances);

// MOVE.C
void			move_real(t_instances *instances, double move_by);
void			move_imaginary(t_instances *instances, double move_by);

// COLOR.C
void			color_pixel_by_iter(int y, int x, int iter,
					t_instances *instances);
void			change_color(t_instances *instances);

// NEEEEEEEEW
uint32_t		ft_color_1(int iter);
uint32_t		ft_color_2(int iter);
uint32_t		ft_color_3(int iter);
uint32_t		ft_color_4(int iter);
uint32_t		ft_color_5(int iter);
uint32_t		ft_color_6(int iter);
uint32_t		ft_color_7(int iter);
uint32_t		ft_color_8(int iter);
uint32_t		ft_color_9(int iter);

// PALETTES.C
uint32_t		get_rgba(int r, int g, int b, int a);

//TERMINATE.C
void			free_instances(t_instances *instances);
void			terminate(t_instances *instances);
void			leak_check(void);

// UTILS.c
void			put_instructions_on_screen(t_instances *instances);
void			print_iter(t_instances *instances);
t_point			*init_point(double y, double x);
t_axe			*init_axe(double start_y, double start_x, double end_y,
					double end_x);
t_mouse			*init_mouse(void);

void			get_mouse_coordinates(t_instances *instances);
double			get_height_of_axe(t_axe *axe);
double			get_width_of_axe(t_axe *axe);
double			get_y_scaled_to_point(int y, t_instances *instances);
double			get_x_scaled_to_point(int x, t_instances *instances);

#endif