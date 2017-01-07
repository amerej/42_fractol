/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:54:10 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/07 19:38:00 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_new_julia(t_app *a)
{
	a->tab_f[0].name = "julia";
	a->tab_f[0].fun = ft_compute_fractal(a, "julia");
}

void	ft_new_mandelbrot(t_app *a)
{
	a->tab_f[1].name = "mandelbrot";
	a->tab_f[1].fun = ft_compute_fractal(a, "mandelbrot");
}

void	ft_new_bship(t_app *a)
{
	a->tab_f[2].name = "bship";
	a->tab_f[2].fun = ft_compute_fractal(a, "bship");
}

void				ft_new_fractal(t_app *a, char *name)
{
	a->tab_f = (t_fractal *)malloc(sizeof(t_fractal) * 3);
	ft_new_julia(a);
	ft_new_mandelbrot(a);
	ft_new_bship(a);
	if (!(ft_strcmp(name, "julia")))
		a->f = &a->tab_f[0];
	if (!(ft_strcmp(name, "mandelbrot")))
		a->f = &a->tab_f[1];
	if (!(ft_strcmp(name, "bship")))
		a->f = &a->tab_f[2];
}
