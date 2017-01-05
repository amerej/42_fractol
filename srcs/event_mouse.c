/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:49:58 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/05 12:46:31 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_scale_mouse(int button, int x, int y, t_app *app)
{
	if (button == 4)
	{
		app->fractal->zoom *= 1.1;
		app->fractal->move.x += ((app->fractal->h / 2) /
			app->fractal->w / 2) / app->fractal->zoom * 10;
		app->fractal->move.y += ((app->fractal->w / 2) /
			app->fractal->h / 2) / app->fractal->zoom * 10;
	}
	if (button == 5)
	{
		app->fractal->zoom /= 1.1;
		app->fractal->move.x += ((app->fractal->h / 2) /
			app->fractal->w / 2) / app->fractal->zoom * 10;
		app->fractal->move.y += ((app->fractal->w / 2) /
			app->fractal->h / 2) / app->fractal->zoom * 10;
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
