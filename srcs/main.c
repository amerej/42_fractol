/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:09:17 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/29 13:04:08 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_expose_hook(t_app *app)
{
	ft_draw(app);
	return (FALSE);
}

int		main(int argc, char *argv[])
{
	t_app	*app;
	char	*name_fractal;

	if (!(argc == 2 && (name_fractal = ft_get_arg(argv[1]))))
		ft_exit_error_str("Usage: ./fractol julia || mandelbrot || sierpinski");
	if (!(app = ft_new_window(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Fractol")))
		ft_exit_error();
	ft_init_fractal(app, name_fractal);
	mlx_expose_hook(app->win, ft_expose_hook, app);
	mlx_key_hook(app->win, ft_key_hook, app);
	mlx_loop(app->mlx);
	return (FALSE);
}
