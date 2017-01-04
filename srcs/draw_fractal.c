/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerej <amerej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 07:44:49 by amerej            #+#    #+#             */
/*   Updated: 2017/01/04 15:39:51 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_put_pixel_img(t_app *app, t_point *p, int color)
{
	int		i;

	i = ((int)p->x * 4) + ((int)p->y * app->size_line);
	app->data[i] = color;
	app->data[++i] = color >> 8;
	app->data[++i] = color >> 16;
}

int				ft_get_color(double c_index)
{
	t_color		c;

	c.channels[0] = (unsigned char)(sin(0.030 * c_index + 6) * 127 + 55);
	c.channels[1] = (unsigned char)(sin(0.005 * c_index + 6) * 200 + 55);
	c.channels[2] = (unsigned char)(sin(0.000 * c_index + 6) * 200 + 55);
	return (c.number);
}

static void		ft_draw_img(t_thread_data *thread)
{
	t_point		p;
	int 		(*fun)(t_fractal*, t_point*) = thread->f->fun;

	p.y = WINDOW_SIZE_Y / NB_THREADS * (thread->i);
	while (p.y < WINDOW_SIZE_Y / NB_THREADS * (thread->i + 1))
	{
		p.x = -1;
		while (++p.x < WINDOW_SIZE_X)
		{
			ft_put_pixel_img(thread->app, &p, (fun)(thread->f, &p));
		}
		++p.y;
	}
	free(thread->f);
	free(thread);
}

void			ft_draw_fractal(t_app *app)
{
	pthread_t		thread_draw[NB_THREADS];
	t_thread_data	*thread;
	int				i;

	app->img_ptr = mlx_new_image(app->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	app->data = mlx_get_data_addr(app->img_ptr, &(app->bpp), &(app->size_line),
		&(app->endian));
	i = -1;
	while (++i < NB_THREADS)
	{
		thread = (t_thread_data *)malloc(sizeof(t_thread_data));
		thread->i = i;
		thread->app = app;
		thread->f = malloc(sizeof(t_fractal));
		ft_memcpy(thread->f, app->fractal, sizeof(t_fractal));
		pthread_create(&thread_draw[thread->i], NULL, (void *)ft_draw_img, thread);
	}
	i = -1;
	while (++i < NB_THREADS)
		pthread_join(thread_draw[i], NULL);
	mlx_put_image_to_window(app->mlx, app->win, app->img_ptr, 0, 0);
	mlx_destroy_image(app->mlx, app->img_ptr);
}
