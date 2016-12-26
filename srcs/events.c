/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:49:58 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/26 07:16:46 by amerej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_hook(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(app->mlx, app->win);
		exit(EXIT_SUCCESS);
	}
	return (FALSE);
}
