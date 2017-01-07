/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:50:29 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/07 15:48:26 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_compute_julia(t_fractal *f, t_point *p)
{
	int		i;

	f->new.r = 1.5 * (p->x - WIN_W / 2) / (0.5 * f->zoom * WIN_W) - f->move.x;
	f->new.i = (p->y - WIN_H / 2) / (0.5 * f->zoom * WIN_H) + f->move.y;
	i = -1;
	while (++i < f->i_max)
	{
		f->old.r = f->new.r;
		f->old.i = f->new.i;
		f->new.r = f->old.r * f->old.r - f->old.i * f->old.i + f->c.r;
		f->new.i = 2 * f->old.r * f->old.i + f->c.i;
		if ((f->new.r * f->new.r + f->new.i * f->new.i) > 4)
			break;
	}
	if (i < f->i_max)
		return (ft_get_color(i + 1 - (log(2) /
			sqrt(f->new.r * f->new.r + f->new.i * f->new.i)) / log(2), f->cs));
	return (0xffffff);
}

static int		ft_compute_mandelbrot(t_fractal *f, t_point *p)
{
	int		i;

	f->z.r = 1.5 * (p->x - WIN_W / 2) / (0.5 * f->zoom * WIN_W) - f->move.x;
	f->z.i = (p->y - WIN_H / 2) / (0.5 * f->zoom * WIN_H) + f->move.y;
	f->new.r = 0;
	f->new.i = 0;
	f->old.r = 0;
	f->old.i = 0;
	i = -1;
	while (++i < f->i_max)
	{
		f->old.r = f->new.r;
		f->old.i = f->new.i;
		f->new.r = f->old.r * f->old.r - f->old.i * f->old.i + f->z.r;
		f->new.i = 2 * f->old.r * f->old.i + f->z.i;
		if ((f->new.r * f->new.r + f->new.i * f->new.i) > 4)
			break;
	}
	if (i < f->i_max)
		return (ft_get_color(i + 1 - (log(2) /
			sqrt(f->new.r * f->new.r + f->new.i * f->new.i)) / log(2), f->cs));
	return (FALSE);
}

static int		ft_compute_bship(t_fractal *f, t_point *p)
{
	int		i;

	f->c.r = 1.5 * (p->x - WIN_W / 2) / (0.5 * f->zoom * WIN_W) - f->move.x;
	f->c.i = (p->y - WIN_H / 2) / (0.5 * f->zoom * WIN_H) + f->move.y;
	f->new.r = 0;
	f->new.i = 0;
	f->old.r = 0;
	f->old.i = 0;
	i = -1;
	while (++i < f->i_max)
	{
		f->old.r = f->new.r;
		f->old.i = f->new.i;
		f->new.r = f->old.r * f->old.r - f->old.i * f->old.i + f->c.r;
		f->new.i = 2 * fabs(f->old.r * f->old.i) + f->c.i;
		if ((f->new.r * f->new.r + f->new.i * f->new.i) > 4)
			break ;
	}
	if (i < f->i_max)
		return (ft_get_color(i + 1 - (log(2) /
			sqrt(f->new.r * f->new.r + f->new.i * f->new.i)) / log(2), f->cs));
	return (FALSE);
}

void			*ft_compute_fractal(char *name)
{
	void	*f;

	if (!(ft_strcmp(name, "julia")))
		f = &ft_compute_julia;
	if (!(ft_strcmp(name, "mandelbrot")))
		f = &ft_compute_mandelbrot;
	if (!(ft_strcmp(name, "bship")))
		f = &ft_compute_bship;
	return (f);
}
