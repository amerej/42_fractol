/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:49:58 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/16 14:07:48 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_hook(int keycode, t_app *env)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(app->env->mlx, app->env->win);
		exit(0);
	}
	return (0);
}
