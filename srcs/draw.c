/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerej <amerej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 07:44:49 by amerej            #+#    #+#             */
/*   Updated: 2016/12/29 11:46:57 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_draw(t_app *app)
{
	app->img_ptr = mlx_new_image(app->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	app->data = mlx_get_data_addr(app->img_ptr, &(app->bpp), &(app->size_line),
		&(app->endian));
	ft_draw_img(app, app->fractal, app->fractal->fun);
	mlx_put_image_to_window(app->mlx, app->win, app->img_ptr, 0, 0);
	mlx_destroy_image(app->mlx, app->img_ptr);
}

unsigned int	ft_get_color(double c_index)
{
	t_color		c;
	c.channels[0] = (unsigned char)(sin(0.016 * c_index + 4) * 120 + 25);
	c.channels[1] = (unsigned char)(sin(0.013 * c_index + 2) * 120 + 25);
	c.channels[2] = (unsigned char)(sin(0.010 * c_index + 1) * 120 + 25);
	c.channels[3] = 255;
	return (c.number);
}

void			ft_put_pixel_img(t_app *app, t_point *p, int color)
{
	int		i;

	i = ((int)p->x * 4) + ((int)p->y * app->size_line);
	app->data[i] = color;
	app->data[++i] = color >> 8;
	app->data[++i] = color >> 16;
}

t_fractal		*ft_init_julia(void)
{
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	f->fun = &ft_compute_julia;
	f->c.r = -0.7;
	f->c.i = 0.27015;
	f->move.x = 0;
	f->move.y = 0;
	f->zoom = 1;
	f->i_max = ITERATION_MAX;
	f->w = WINDOW_SIZE_X;
	f->h = WINDOW_SIZE_Y;
	return (f);
}

void	ft_draw_img(t_app *app, t_fractal *f, double (*fun)(t_app*, t_fractal*, t_point*))
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

double		ft_compute_julia(t_app *app, t_fractal *f, t_point *p)
{
	int		i;

	f->new.r = 1.5 * (p->x - f->w / 2) / (0.5 * f->zoom * f->w) + f->move.x;
	f->new.i = (p->y - f->h / 2) / (0.5 * f->zoom * f->h) + f->move.y;
	i = -1;
	while (++i < f->i_max)
	{
		f->old.r = f->new.r;
		f->old.i = f->new.i;
		f->new.r = (f->old.r * f->old.r) - (f->old.i * f->old.i) + f->c.r;
		f->new.i = 2 * f->old.r * f->old.i + f->c.i;
		if (((f->new.r * f->new.r) + (f->new.i * f->new.i)) > 4)
			break;
	}
	return (i + 1 - (log(2) / sqrt(f->new.r * f->new.r + f->new.i * f->new.i)) / log(2));
}

void	ft_init_fractal(t_app *app, char *name_fractal)
{
	if (ft_strcmp(name_fractal, "julia") == 0)
		app->fractal = ft_init_julia();
	// if (ft_strcmp(name_fractal, "mandelbrot") == 0)
	// 	app->fractal = ft_init_mandelbrot();
	// if (ft_strcmp(name_fractal, "bship") == 0)
	// 	app->fractal = ft_init_bship();
}
