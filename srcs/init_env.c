/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerej <amerej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 07:50:24 by amerej            #+#    #+#             */
/*   Updated: 2016/12/29 18:03:23 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_app	*ft_init(void)
{
	t_app	*app;

	if (!(app = (t_app *)malloc(sizeof(t_app))))
	{
		ft_putendl_fd("ERROR >> ft_init >> malloc !", 2);
		return (NULL);
	}
	if (!(app->mlx = mlx_init()))
	{
		ft_free_ptr(app);
		ft_putendl_fd("ERROR >> ft_init >> mlx_init !", 2);
		return (NULL);
	}
	return (app);
}

t_app			*ft_new_window(int width, int height, char *title)
{
	t_app	*app;

	if (!(app = ft_init()))
		return (NULL);
	if (!(app->win = mlx_new_window(app->mlx, width, height, title)))
	{
		ft_free_ptr(app);
		ft_putendl_fd("ERROR >> ft_new_window >> mlx_new_window !", 2);
		return (NULL);
	}
	return (app);
}
