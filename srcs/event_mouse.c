/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:49:58 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/06 19:45:12 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_scale_mouse(int button, int x, int y, t_app *a)
{
	if (button == 1 || button == 4)
	{
		a->f->move.x += 0.002 * (WIN_W / 2 - x) / a->f->zoom;
		a->f->move.y -= 0.002 * (WIN_H / 2 - y) / a->f->zoom;
		if (button == 4)
			a->f->zoom *= 2;
	}
	if (button == 5)
		a->f->zoom = (a->f->zoom <= 1) ? 1 : a->f->zoom / 2;
}

int				ft_motion_hook(int x, int y, t_app *a)
{
	if (a->f->stop_motion)
		return (FALSE);
	if (x >= 0 && y >= 0 && x <= a->f->w && y <= a->f->h)
	{
		a->f->c.r = -0.7 + (double)x / WIN_W;
		a->f->c.i = 0.27015 + (double)y / WIN_H;
		ft_draw_fractal(a);
	}
	return (FALSE);
}

int				ft_mouse_hook(int button, int x, int y, t_app *a)
{
	ft_scale_mouse(button, x, y, a);
	ft_draw_fractal(a);
	return (FALSE);
}
