/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:10:36 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/28 18:15:46 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "../minilibx/osx/mlx.h"
# include "keycode_osx.h"

# define WINDOW_SIZE_X 800
# define WINDOW_SIZE_Y 600

# define ITERATION_MAX 50

typedef union		u_color
{
	unsigned int	number;
	unsigned char	channels[4];
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
	t_complex		c;
	t_complex		z;
	t_point			p1;
	t_point			p2;
	double			zn;
	double			zoom;
	double			tmp;
	double			c_index;
	int				i;
	int				w;
	int				h;
	int				i_max;
	void			*function;
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

t_app				*ft_new_window(int width, int height, char *title);

int					ft_key_hook(int keycode, t_app *app);

char				*ft_get_arg(char *argv);

void				ft_put_pixel_img(t_app *app, t_point *p, int color);
t_fractal			*ft_init_julia(void);
unsigned int		ft_get_color(double c_index);
void				ft_draw_img(t_app *app, t_fractal *f, double (*fun)(t_app*, t_fractal*, t_point*));
double				ft_compute_julia(t_app *app, t_fractal *f, t_point *p);
void				ft_init_fractal(t_app *app, char *name_fractal);
void				ft_draw(t_app *app);
#endif
