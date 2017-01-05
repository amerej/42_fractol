/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:49:06 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/05 12:02:56 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_julia(t_fractal *f)
{
	f->fun = ft_compute_fractal("julia");
	f->name = "julia";
	f->c.r = -0.7;
	f->c.i = 0.27015;
	f->move.x = 0;
	f->move.y = 0;
	f->zoom = 1;
	f->i_max = ITERATION_MAX;
	f->w = WINDOW_SIZE_X;
	f->h = WINDOW_SIZE_Y;
	f->stop_motion = FALSE;
}

static void		ft_init_mandelbrot(t_fractal *f)
{
	f->fun = ft_compute_fractal("mandelbrot");
	f->name = "mandelbrot";
	f->move.x = -0.5;
	f->move.y = 0;
	f->zoom = 1;
	f->i_max = ITERATION_MAX;
	f->w = WINDOW_SIZE_X;
	f->h = WINDOW_SIZE_Y;
}

static void		ft_init_bship(t_fractal *f)
{
	f->fun = ft_compute_fractal("bship");
	f->name = "bship";
	f->move.x = -3;
	f->move.y = -2;
	f->zoom = 1;
	f->i_max = ITERATION_MAX;
	f->w = WINDOW_SIZE_X / (1.6 + 1.1);
	f->h = WINDOW_SIZE_Y / (1.7 + 0.7);
}

static void		ft_init_sierpinski(t_fractal *f)
{
	f->fun = ft_compute_fractal("sierpinski");
	f->name = "sierpinski";
	f->move.x = 0;
	f->move.y = 0;
	f->zoom = 1;
	f->i_max = 10;
	f->w = WINDOW_SIZE_X;
	f->h = WINDOW_SIZE_Y;
}

void	ft_init_fractal(t_app *app, char *name_fractal)
{
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	f->cs = (t_cscheme *)malloc(sizeof(t_cscheme));
	if (!(ft_strcmp(name_fractal, "julia")))
		ft_init_julia(f);
	if (!(ft_strcmp(name_fractal, "mandelbrot")))
		ft_init_mandelbrot(f);
	if (!(ft_strcmp(name_fractal, "bship")))
		ft_init_bship(f);
	if (!(ft_strcmp(name_fractal, "sierpinski")))
		ft_init_sierpinski(f);
	app->fractal = f;
	ft_init_color(f->cs);
}
