/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:49:58 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/04 13:36:32 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_hook(int button, int x, int y, t_app *app)
{
	if (button == 1 || button == 4)
	{
		app->fractal->move.x += 0.002 * (WINDOW_SIZE_X / 2 - x) / app->fractal->zoom;
		app->fractal->move.y -= 0.002 * (WINDOW_SIZE_Y / 2 - y) / app->fractal->zoom;
		if (button == 4)
			app->fractal->zoom *= 2;
	}
	if (button == 5)
		app->fractal->zoom = app->fractal->zoom <= 1 ? 1 : app->fractal->zoom / 2;
	ft_draw_fractal(app);
	return (FALSE);
}

int		ft_motion_hook(int x, int y, t_app *app)
{
	if (app->fractal->stop_motion)
		return (FALSE);
	if (x >= 0 && y >= 0 && x <= app->fractal->w && y <= app->fractal->h)
	{
		// app->fractal->c.r = (double)x / (double)app->fractal->w * 4 - 2;
		// app->fractal->c.i = (double)y / (double)app->fractal->h * 4 - 2;
		app->fractal->c.r = -0.7 + (double)x / WINDOW_SIZE_X;
		app->fractal->c.i = 0.27015 + (double)y / WINDOW_SIZE_Y;
		ft_draw_fractal(app);
	}
	return (FALSE);
}

int		ft_key_hook(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(app->mlx, app->win);
		free(app->fractal);
		free(app);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 49)
		app->fractal->stop_motion = app->fractal->stop_motion ? 0 : 1;
	ft_draw_fractal(app);
	return (FALSE);
}
