/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:09:17 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/26 07:50:52 by amerej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char *argv[])
{
	t_app	*app;
	char	*name_fractal;

	if (!(argc == 2 && (name_fractal = ft_get_arg(argv[1]))))
		ft_exit_error_str("Usage: ./fractol julia || mandelbrot || sierpinski");
	if (!(app = ft_new_window(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Fractol")))
		ft_exit_error();
	ft_draw_fractal(app, name_fractal);
	mlx_key_hook(app->win, ft_key_hook, app);
	mlx_loop(app->mlx);
	return (0);
}
