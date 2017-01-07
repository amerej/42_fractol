/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:49:06 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/07 15:47:56 by aditsch          ###   ########.fr       */
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
	a->cs = (t_cscheme *)malloc(sizeof(t_cscheme));
	ft_init_julia(a->tab_f[0]);
	ft_init_mandelbrot(a->tab_f[1]);
	ft_init_bship(a->tab_f[2]);
	ft_init_color(a->cs);
}
