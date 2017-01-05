/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:49:58 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/05 10:57:12 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		 ft_scale_mouse(int button, int x, int y, t_app *app)
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

int		ft_motion_hook(int x, int y, t_app *app)
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

int		ft_mouse_hook(int button, int x, int y, t_app *app)
{
	ft_scale_mouse(button, x, y, app);
	ft_draw_fractal(app);
	return (FALSE);
}

static	void	ft_scale_key(int keycode, t_app *app)
{
	double	zr;

	if (keycode == KEY_KP_PLUS)
	{
		app->fractal->zoom *= 1.1;
		zr = app->fractal->zoom;
		app->fractal->move.x += ((app->fractal->h / 2) /
			app->fractal->w / 2) / zr * 10;
		app->fractal->move.y += ((app->fractal->w / 2) /
			app->fractal->h / 2) / zr * 10;
	}
	else if (keycode == KEY_KP_MINUS)
	{
		app->fractal->zoom /= 1.1;
		zr = app->fractal->zoom;
		app->fractal->move.x += ((app->fractal->h / 2) /
			app->fractal->w / 2) / zr * 10;
		app->fractal->move.y += ((app->fractal->w / 2) /
			app->fractal->h / 2) / zr * 10;
	}
}

static	void	ft_translate(int keycode, t_app *app)
{
	if (keycode == KEY_UP)
		app->fractal->move.y += 10 / (app->fractal->zoom * 20);
	else if (keycode == KEY_DOWN)
		app->fractal->move.y -= 10 / (app->fractal->zoom * 20);
	else if (keycode == KEY_LEFT)
		app->fractal->move.x += 10 / (app->fractal->zoom * 20);
	else if (keycode == KEY_RIGHT)
		app->fractal->move.x -= 10 / (app->fractal->zoom * 20);
}

static void		ft_reset(int keycode, t_app *app)
{
	if (keycode == KEY_KP_DOT)
	{
		if(!ft_strcmp(app->fractal->name, "julia"))
			ft_init_fractal(app, app->fractal->name);
	}
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
	ft_translate(keycode, app);
	ft_scale_key(keycode, app);
	ft_reset(keycode, app);
	ft_draw_fractal(app);
	return (FALSE);
}
