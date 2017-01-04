/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:09:17 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/04 14:26:32 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_expose_hook(t_app *app)
{
	ft_draw_fractal(app);
	return (FALSE);
}

int		main(int argc, char *argv[])
{
	t_app	*app;
	char	*name_fractal;

	if (!(argc == 2 && (name_fractal = ft_get_user_input(argv[1]))))
		ft_exit_error_str("Usage: ./fractol julia || mandelbrot || bship");
	if (!(app = ft_new_window(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Fractol")))
		ft_exit_error();
	ft_init_fractal(app, name_fractal);
	mlx_hook(app->win, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion_hook, app);
	mlx_key_hook(app->win, ft_key_hook, app);
	mlx_mouse_hook(app->win, ft_mouse_hook, app);
	mlx_expose_hook(app->win, ft_expose_hook, app);
	mlx_loop(app->mlx);
	return (FALSE);
}
