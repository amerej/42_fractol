/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerej <amerej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 07:44:49 by amerej            #+#    #+#             */
/*   Updated: 2017/01/07 19:05:46 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_put_pixel_img(t_app *a, t_point *p, int color)
{
	int	i;

	i = ((int)p->x * 4) + ((int)p->y * a->size_line);
	a->data[i] = color;
	a->data[++i] = color >> 8;
	a->data[++i] = color >> 16;
}

static void		ft_draw_img(t_thread_data *thread)
{
	t_point		p;
	int 		(*fun)(t_fractal*, t_point*);
	fun = thread->f->fun;

	p.y = WIN_H / NB_THREAD * (thread->i);
	while (p.y < WIN_H / NB_THREAD * (thread->i + 1))
	{
		p.x = 0;
		while (p.x < WIN_W)
		{
			ft_put_pixel_img(thread->app, &p, (fun)(thread->f, &p));
			++p.x;
		}
		++p.y;
	}
	free(thread->f);
	free(thread);
}

static void		ft_multi_thread_draw(t_app *app)
{
	pthread_t		thread_draw[NB_THREAD];
	t_thread_data	*thread;
	int				i;

	i = 0;
	while (i < NB_THREAD)
	{
		thread = (t_thread_data *)malloc(sizeof(t_thread_data));
		thread->i = i;
		thread->app = app;
		thread->f = (t_fractal *)malloc(sizeof(t_fractal));
		ft_memcpy(thread->f, app->f, sizeof(t_fractal));
		pthread_create(&thread_draw[thread->i], NULL,
			(void *)ft_draw_img, thread);
		++i;
	}
	i = 0;
	while (i < NB_THREAD)
	{
		pthread_join(thread_draw[i], NULL);
		++i;
	}
}

void			ft_draw_fractal(t_app *a)
{
	a->img_ptr = mlx_new_image(a->mlx, WIN_W, WIN_H);
	a->data = mlx_get_data_addr(a->img_ptr, &(a->bpp), &(a->size_line),
		&(a->endian));
	ft_multi_thread_draw(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img_ptr, 0, 0);
	mlx_destroy_image(a->mlx, a->img_ptr);
}
