/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:50:29 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/29 13:08:26 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_compute_julia(t_app *app, t_fractal *f, t_point *p)
{
	int		i;

	f->new.r = 1.5 * (p->x - f->w / 2) / (0.5 * f->zoom * f->w) + f->move.x;
	f->new.i = (p->y - f->h / 2) / (0.5 * f->zoom * f->h) + f->move.y;
	i = -1;
	while (++i < f->i_max)
	{
		f->old.r = f->new.r;
		f->old.i = f->new.i;
		f->new.r = (f->old.r * f->old.r) - (f->old.i * f->old.i) + f->c.r;
		f->new.i = 2 * f->old.r * f->old.i + f->c.i;
		if (((f->new.r * f->new.r) + (f->new.i * f->new.i)) > 4)
			break;
	}
	return (i + 1 - (log(2) /
		sqrt(f->new.r * f->new.r + f->new.i * f->new.i)) / log(2));
}
