/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:35:12 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/22 01:57:41 by amerej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libg.h"

t_env	*ft_new_window(int size_x, int size_y, char *title)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))));
		return (NULL);
	if (!(e->mlx = mlx_init()))
		return (NULL);
	if (!(e->win = mlx_new_window(e->mlx, size_x, size_y, title)))
		return (NULL);
	return (e);
}
