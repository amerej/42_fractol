/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:49:06 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/06 21:47:20 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_julia(t_fractal *f)
{
	f->c.r = -0.7;
	f->c.i = 0.27015;
	f->move.x = 0;
	f->move.y = 0;
	f->zoom = 1;
	f->i_max = I_MAX;
	f->stop_motion = FALSE;
}

static void		ft_init_mandelbrot(t_fractal *f)
{
	f->move.x = 0.5;
	f->move.y = 0;
	f->zoom = 1;
	f->i_max = I_MAX;
}

static void		ft_init_bship(t_fractal *f)
{
	f->move.x = 0.5;
	f->move.y = -0.5;
	f->zoom = 1;
	f->i_max = I_MAX;
}

void	ft_init_fractal(t_app *a, char *name)
{
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	f->cs = (t_cscheme *)malloc(sizeof(t_cscheme));
	if (!(ft_strcmp(name, "julia")))
	{
		f->name = "julia";
		f->fun = ft_compute_fractal("julia");
		ft_init_julia(f);
	}
	if (!(ft_strcmp(name, "mandelbrot")))
	{
		f->name = "mandelbrot";
		f->fun = ft_compute_fractal("mandelbrot");
		ft_init_mandelbrot(f);
	}
	if (!(ft_strcmp(name, "bship")))
	{
		f->name = "bship";
		f->fun = ft_compute_fractal("bship");
		ft_init_bship(f);
	}
	a->f = f;
	ft_init_color(f->cs);
}
