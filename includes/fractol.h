/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:10:36 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/16 14:07:43 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../libg/libg.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define ITERATION_MAX 128

typedef struct		s_complex
{
	long double		r;
	long double		i;
}					t_complex;

typedef struct		s_fractal
{
	t_complex		c;
	t_complex		z;
	t_point_ld		p1;
	t_point_ld		p2;
	long double		zoom;
	long double		tmp;
	int				iter;
	int				iter_max;
}					t_fractal;

typedef struct		s_app
{
	t_env			*env;
	t_fractal		*fractal;
}					t_app;

int				ft_key_hook(int keycode, t_env *env);
#endif
