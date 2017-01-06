/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:49:58 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/06 15:06:51 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_scale_mouse(int button, int x, int y, t_app *app)
{
	if (button == 1 || button == 4)
	{
		app->fractal->move.x += 0.002 *
			(WINDOW_SIZE_X / 2 - x) / app->fractal->zoom;
		app->fractal->move.y -= 0.002 *
			(WINDOW_SIZE_Y / 2 - y) / app->fractal->zoom;
		if (button == 4)
		{
			app->fractal->zoom *= 2;
		}
	}
	if (button == 5)
	{
		app->fractal->zoom =
			(app->fractal->zoom <= 1) ? 1 : app->fractal->zoom / 2;
	}
}

int				ft_motion_hook(int x, int y, t_app *app)
{
	if (app->fractal->stop_motion)
		return (FALSE);
	if (x >= 0 && y >= 0 && x <= app->fractal->w && y <= app->fractal->h)
	{
		app->fractal->c.r = -0.7 + (double)x / WINDOW_SIZE_X;
		app->fractal->c.i = 0.27015 + (double)y / WINDOW_SIZE_Y;
		ft_draw_fractal(app);
	}
	return (FALSE);
}

int				ft_mouse_hook(int button, int x, int y, t_app *app)
{
	ft_scale_mouse(button, x, y, app);
	ft_draw_fractal(app);
	return (FALSE);
}