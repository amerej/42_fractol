/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:09:17 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/08 18:45:39 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_expose_hook(t_app *a)
{
	ft_draw_fractal(a);
	return (FALSE);
}

int			main(int argc, char *argv[])
{
	t_app	*a;

	if (!(argc == 2 && ft_get_user_input(argv[1])))
		ft_exit_error_str("Usage: ./fractol julia || mandelbrot || bship");
	if (!(a = ft_new_window(WIN_W, WIN_H, "Fractol")))
		ft_exit_error();
	a->name_fractal = argv[1];
	ft_new_fractal_tab(a);
	ft_new_cscheme_tab(a);
	ft_select_fractal(a);
	mlx_hook(a->win, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion_hook, a);
	mlx_key_hook(a->win, ft_key_hook, a);
	mlx_mouse_hook(a->win, ft_mouse_hook, a);
	mlx_expose_hook(a->win, ft_expose_hook, a);
	mlx_loop(a->mlx);
	return (FALSE);
}
