/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerej <amerej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 07:44:49 by amerej            #+#    #+#             */
/*   Updated: 2016/12/29 13:32:48 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void				ft_put_pixel_img(t_app *app, t_point *p, int color)
{
	int		i;

	i = ((int)p->x * 4) + ((int)p->y * app->size_line);
	app->data[i] = color;
	app->data[++i] = color >> 8;
	app->data[++i] = color >> 16;
}

static unsigned int		ft_get_color(double c_index)
{
	t_color		c;
	double		freq;

	freq = .3;
	c.channels[0] = (unsigned char)(sin(0.016 * c_index + 4) * 127 + 128);
	c.channels[1] = (unsigned char)(sin(0.013 * c_index + 2) * 127 + 128);
	c.channels[2] = (unsigned char)(sin(0.010 * c_index + 1) * 127 + 128);
	c.channels[3] = 255;
	return (c.number);
}

static void				ft_draw_img(t_app *app, t_fractal *f,
							double (*fun)(t_app*, t_fractal*, t_point*))
{
	t_point			p;

	p.y = -1;
	while (++p.y < WINDOW_SIZE_Y)
	{
		p.x = -1;
		while (++p.x < WINDOW_SIZE_X)
			ft_put_pixel_img(app, &p, ft_get_color((*fun)(app, f, &p)));
	}
}

void					ft_draw_fractal(t_app *app)
{
	app->img_ptr = mlx_new_image(app->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	app->data = mlx_get_data_addr(app->img_ptr, &(app->bpp), &(app->size_line),
		&(app->endian));
	ft_draw_img(app, app->fractal, app->fractal->fun);
	mlx_put_image_to_window(app->mlx, app->win, app->img_ptr, 0, 0);
	mlx_destroy_image(app->mlx, app->img_ptr);
}
