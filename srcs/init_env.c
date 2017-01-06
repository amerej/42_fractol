/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerej <amerej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 07:50:24 by amerej            #+#    #+#             */
/*   Updated: 2017/01/06 19:53:10 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_app	*ft_init(void)
{
	t_app	*a;

	if (!(a = (t_app *)malloc(sizeof(t_app))))
	{
		ft_putendl_fd("ERROR >> ft_init >> malloc !", 2);
		return (NULL);
	}
	if (!(a->mlx = mlx_init()))
	{
		ft_free_ptr(a);
		ft_putendl_fd("ERROR >> ft_init >> mlx_init !", 2);
		return (NULL);
	}
	return (a);
}

t_app			*ft_new_window(int width, int height, char *title)
{
	t_app	*a;

	if (!(a = ft_init()))
		return (NULL);
	if (!(a->win = mlx_new_window(a->mlx, width, height, title)))
	{
		ft_free_ptr(a);
		ft_putendl_fd("ERROR >> ft_new_window >> mlx_new_window !", 2);
		return (NULL);
	}
	return (a);
}
