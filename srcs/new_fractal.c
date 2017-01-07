/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:54:10 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/07 17:19:45 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractal	ft_new_julia(void)
{
	t_fractal	f;
	f = (t_fractal)malloc(sizeof(t_fractal));
	f.name = "julia";
	f.fun = ft_compute_fractal("julia");
	return (f);
}

static t_fractal	ft_new_mandelbrot(void)
{
	t_fractal	f;
	f = (t_fractal)malloc(sizeof(t_fractal));
	f.name = "mandelbrot";
	f.fun = ft_compute_fractal("mandelbrot");
	return (f);
}

static t_fractal	ft_new_bship(void)
{
	t_fractal	f;
	f = (t_fractal)malloc(sizeof(t_fractal));
	f.name = "bship";
	f.fun = ft_compute_fractal("bship");
	return (f);
}

void				ft_new_fractal(t_app *a, char *name)
{
	a->tab_f[0] = ft_new_julia();
	a->tab_f[1] = ft_new_mandelbrot();
	a->tab_f[2] = ft_new_bship();
	if (!(ft_strcmp(name, "julia")))
		a->f = a->tab_f[0];
	if (!(ft_strcmp(name, "mandelbrot")))
		a->f = a->tab_f[1];
	if (!(ft_strcmp(name, "bship")))
		a->f = a->tab_f[2];
}