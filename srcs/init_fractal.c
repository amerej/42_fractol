/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:49:06 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/03 17:37:32 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractal	*ft_init_julia(void)
{
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	f->fun = ft_compute_fractal("julia");
	f->c.r = -0.7;
	f->c.i = 0.27015;
	f->move.x = 0;
	f->move.y = 0;
	f->zoom = 1;
	f->i_max = ITERATION_MAX;
	f->w = WINDOW_SIZE_X;
	f->h = WINDOW_SIZE_Y;
	f->stop_motion = FALSE;
	return (f);
}

static t_fractal	*ft_init_mandelbrot(void)
{
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	f->fun = ft_compute_fractal("mandelbrot");
	f->move.x = -0.5;
	f->move.y = 0;
	f->zoom = 1;
	f->i_max = ITERATION_MAX;
	f->w = WINDOW_SIZE_X;
	f->h = WINDOW_SIZE_Y;
	return (f);
}

static t_fractal	*ft_init_bship(void)
{
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	f->fun = ft_compute_fractal("bship");
	f->move.x = -3;
	f->move.y = -2;
	f->zoom = 1;
	f->i_max = ITERATION_MAX;
	f->w = WINDOW_SIZE_X / (1.6 + 1.1);
	f->h = WINDOW_SIZE_Y / (1.7 + 0.7);
	return (f);
}

static t_fractal	*ft_init_sierpinski(void)
{
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	f->fun = ft_compute_fractal("sierpinski");
	f->move.x = 0;
	f->move.y = 0;
	f->zoom = 1;
	f->i_max = 10;
	f->w = WINDOW_SIZE_X;
	f->h = WINDOW_SIZE_Y;
	return (f);
}

void				ft_init_fractal(t_app *app, char *name_fractal)
{
	if (!(ft_strcmp(name_fractal, "julia")))
		app->fractal = ft_init_julia();
	if (!(ft_strcmp(name_fractal, "mandelbrot")))
		app->fractal = ft_init_mandelbrot();
	if (!(ft_strcmp(name_fractal, "bship")))
		app->fractal = ft_init_bship();
	if (!(ft_strcmp(name_fractal, "sierpinski")))
		app->fractal = ft_init_sierpinski();
}
