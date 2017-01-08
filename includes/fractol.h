/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:10:36 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/08 19:19:03 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <pthread.h>
# include "../minilibx/osx/mlx.h"
# include "keycode_osx.h"

# define WIN_W 800
# define WIN_H 600

# define I_MIN 50
# define I_MAX 250
# define NB_THREAD 4

typedef struct		s_cscheme
{
	double			freq1;
	double			freq2;
	double			freq3;
	int				phase1;
	int				phase2;
	int				phase3;
	int				amp1;
	int				amp2;
	int				amp3;
	int				center1;
	int				center2;
	int				center3;
}					t_cscheme;

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
	t_complex		new;
	t_complex		old;
	t_point			move;
	double			zoom;
	int				i_max;
	char			stop_motion;
}					t_fractal;

typedef struct		s_app
{
	char			*name_fractal;
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	t_fractal		*f;
	t_fractal		*tab_f;
	t_cscheme		*cs;
	t_cscheme		*tab_cs;
}					t_app;

typedef struct		s_thread_data
{
	t_app			*app;
	t_fractal		*f;
	t_cscheme		*cs;
	int				i;
}					t_thread_data;

t_app				*ft_new_window(int width, int height, char *title);
char				*ft_get_user_input(char *argv);
void				*ft_compute_fractal(char *name);
void				ft_draw_fractal(t_app *app);
int					ft_get_color(double c_index, t_cscheme *cs);
int					ft_key_hook(int keycode, t_app *app);
int					ft_motion_hook(int x, int y, t_app *app);
int					ft_mouse_hook(int button, int x, int y, t_app *app);
void				ft_new_fractal_tab(t_app *a);
void				ft_init_fractal_tab(t_fractal *t);
void				ft_select_fractal(t_app *a);
int					ft_compute_julia(t_fractal *f, t_cscheme *cs, t_point *p);
int					ft_compute_mandelbrot(t_fractal *f, t_cscheme *cs, t_point *p);
int					ft_compute_bship(t_fractal *f, t_cscheme *cs, t_point *p);
void				ft_new_cscheme_tab(t_app *a);
#endif
