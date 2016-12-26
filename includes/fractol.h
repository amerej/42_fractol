/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:10:36 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/26 07:19:21 by amerej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../libg/libg.h"

# define WINDOW_SIZE_X 800
# define WINDOW_SIZE_Y 600

# define NB_FRACTALS 3
# define ITERATION_MAX 10

typedef union		u_color
{
	unsigned int	nb;
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
	t_complex		c;
	t_complex		z;
	t_point			p1;
	t_point			p2;
	double			zn;
	double			zoom;
	double			tmp;
	double			c_index;
	int				i;
	int				i_max;
	int				pixel_color;

}					t_fractal;

typedef struct		s_app
{
	void			*mlx;
	void			*win;
	t_image			*img;
	t_fractal		*fractal;
}					t_app;

int					ft_key_hook(int keycode, t_app *app);

char				*ft_get_arg(char *argv);
#endif
