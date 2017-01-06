/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:05:19 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/06 15:06:42 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_scale(int keycode, t_app *app)
{
	if (keycode == KEY_KP_PLUS)
	{
		app->fractal->zoom *= 1.1;
		app->fractal->move.x += ((WINDOW_SIZE_Y / 2) /
			WINDOW_SIZE_X / 2) / app->fractal->zoom * 10;
		app->fractal->move.y += ((WINDOW_SIZE_X / 2) /
			WINDOW_SIZE_Y / 2) / app->fractal->zoom * 10;
	}
	else if (keycode == KEY_KP_MINUS)
	{
		app->fractal->zoom /= 1.1;
		app->fractal->move.x += ((WINDOW_SIZE_Y / 2) /
			WINDOW_SIZE_X / 2) / app->fractal->zoom * 10;
		app->fractal->move.y += ((WINDOW_SIZE_X / 2) /
			WINDOW_SIZE_Y / 2) / app->fractal->zoom * 10;
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
		if(!ft_strcmp(app->fractal->name, "julia") ||
			!ft_strcmp(app->fractal->name, "mandelbrot") ||
			!ft_strcmp(app->fractal->name, "bship"))
			ft_init_fractal(app, app->fractal->name);
	}
}

static void		ft_mod_iter(int keycode, t_app *app)
{
	if (keycode == KEY_PAGE_UP)
	{
		app->fractal->i_max += 10;
	}
	else if (keycode == KEY_PAGE_DOWN)
	{
		app->fractal->i_max =
			(app->fractal->i_max <= 50) ? 50 : app->fractal->i_max - 10;
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
	ft_scale(keycode, app);
	ft_reset(keycode, app);
	ft_mod_iter(keycode, app);
	ft_draw_fractal(app);
	return (FALSE);
}