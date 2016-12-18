/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:35:12 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/16 14:05:59 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libg.h"

t_env	*ft_init_env(int size_x, int size_y, char *title)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	if ((e->mlx = mlx_init()) == NULL)
		return (NULL);
	if ((e->win = mlx_new_window(e->mlx, size_x, size_y, title)) == NULL)
		return (NULL);
	return (e);
}
