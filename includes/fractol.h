/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:10:36 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/05 10:57:34 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
#include <pthread.h>
# include "../minilibx/osx/mlx.h"
# include "keycode_osx.h"

# define WINDOW_SIZE_X 800
# define WINDOW_SIZE_Y 600

# define ITERATION_MAX 128
# define NB_THREAD 4

typedef union		u_color
{
	int				number;
	unsigned char	channels[3];
}					t_color;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_fractal
{
	void			*fun;
	t_complex		c;
	t_complex		z;
	t_complex		new;
	t_complex		old;
	t_point			p;
	t_point			move;
	double			zoom;
	int				i_max;
	int				w;
	int				h;
	char			stop_motion;
	char			*name;
}					t_fractal;

typedef struct		s_app
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	t_fractal		*fractal;
}					t_app;

typedef struct		s_thread_data
{
	t_app			*app;
	t_fractal		*f;
	int				i;
}					t_thread_data;

t_app				*ft_new_window(int width, int height, char *title);
char				*ft_get_user_input(char *argv);
void				ft_init_fractal(t_app *app, char *name_fractal);
void				*ft_compute_fractal(char *name_fractal);
void				ft_draw_fractal(t_app *app);
int					ft_get_color(double c_index);
int					ft_key_hook(int keycode, t_app *app);
int					ft_motion_hook(int x, int y, t_app *app);
int					ft_mouse_hook(int button, int x, int y, t_app *app);
#endif
