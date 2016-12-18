/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:09:17 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/16 14:07:54 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char *argv[])
{
	t_app	*app;

	if (argc < 2)
		ft_exit_message("Usage: ./fractol julia || mandelbrot || carpet\n");
	if (!(app->env = ft_init_env(WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol")))
		ft_exit_message("Error Init Fractol\n");
	mlx_key_hook(app->env->win, ft_key_hook, app->env);
	mlx_loop(app->env->mlx);
	return (0);
}
