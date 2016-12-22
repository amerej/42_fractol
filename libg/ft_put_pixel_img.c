/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:49:43 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/22 02:09:40 by amerej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libg.h"

void	ft_put_pixel_img(t_env *e, void *point, int color)
{
	int		i;

	i = ((int)point->x * 4) + ((int)point->y * e->size_line);
	e->data[i] = color;
	e->data[++i] = color >> 8;
	e->data[++i] = color >> 16;
}
