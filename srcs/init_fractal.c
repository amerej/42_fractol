/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:49:06 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/08 19:35:24 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_fractal_tab(t_fractal *t)
{
	t[0] = (t_fractal){ft_compute_julia, {-0.7, 0.27015},
		{0, 0}, {0, 0}, {0, 0}, 1, I_MAX, TRUE};
	t[1] = (t_fractal){ft_compute_mandelbrot, {0, 0},
		{0, 0}, {0, 0}, {0.5, 0}, 1, I_MAX, FALSE};
	t[2] = (t_fractal){ft_compute_bship, {0, 0},
		{0, 0}, {0, 0}, {0.5, -0.5}, 1, I_MAX, FALSE};
}

void	ft_new_fractal_tab(t_app *a)
{
	a->tab_f = (t_fractal *)malloc(sizeof(t_fractal) * 3);
	ft_init_fractal_tab(a->tab_f);
}

void	ft_select_fractal(t_app *a)
{
	if (!(ft_strcmp(a->name_fractal, "julia")))
		a->f = &a->tab_f[0];
	if (!(ft_strcmp(a->name_fractal, "mandelbrot")))
		a->f = &a->tab_f[1];
	if (!(ft_strcmp(a->name_fractal, "bship")))
		a->f = &a->tab_f[2];
}
