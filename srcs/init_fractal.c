/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:49:06 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/29 13:06:08 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_init_fractal(t_app *app, char *name_fractal)
{
	if (ft_strcmp(name_fractal, "julia") == 0)
		app->fractal = ft_init_julia();
	// if (ft_strcmp(name_fractal, "mandelbrot") == 0)
	// 	app->fractal = ft_init_mandelbrot();
	// if (ft_strcmp(name_fractal, "bship") == 0)
	// 	app->fractal = ft_init_bship();
}

static t_fractal	*ft_init_julia(void)
{
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	f->fun = &ft_compute_julia;
	f->c.r = -0.7;
	f->c.i = 0.27015;
	f->move.x = 0;
	f->move.y = 0;
	f->zoom = 1;
	f->i_max = ITERATION_MAX;
	f->w = WINDOW_SIZE_X;
	f->h = WINDOW_SIZE_Y;
	return (f);
}
