/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerej <amerej@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 07:44:49 by amerej            #+#    #+#             */
/*   Updated: 2016/12/26 07:49:06 by amerej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_put_pixel_img(t_app *app, t_point *p, int color);
t_fractal		*ft_init_julia(void);
unsigned int	ft_get_color(double c_index);
void			ft_draw_img(t_app *app, t_fractal *f, double (*fun)(t_app*, t_fractal*, t_point*));
double			ft_compute_julia(t_app *app, t_fractal *f, t_point *p);

unsigned int	ft_get_color(double c_index)
{
	t_color		c;
	c.channels[0] = (unsigned char)(sin(0.016 * c_index + 4) * 230 + 25);
	c.channels[1] = (unsigned char)(sin(0.013 * c_index + 2) * 230 + 25);
	c.channels[2] = (unsigned char)(sin(0.010 * c_index + 1) * 230 + 25);
}

void			ft_put_pixel_img(t_app *app, t_point *p, int color)
{
	int		i;

	i = ((int)p->x * 4) + ((int)p->y * app->img->size_line);
	app->img->data[i] = color;
	app->img->data[++i] = color >> 8;
	app->img->data[++i] = color >> 16;
}

t_fractal		*ft_init_julia(void)
{
	t_fractal	*f;

	f->c.r = 0.285;
	f->c.i = 0.010;
	f->z.r = 0;
	f->z.i = 0;
	f->p1.x = 0;
	f->p2.x = 0;
	f->p1.y = 0;
	f->p2.y = 0;
	f->zoom = 0.5;
	f->tmp = 0;
	f->i = 0;
	f->i_max = ITERATION_MAX;
	return (f);
}

void	ft_draw_img(t_app *app, t_fractal *f, double (*fun)(t_app*, t_fractal*, t_point*))
{
	t_point			p;
	unsigned int	color;

	p.y = -1;
	while (++p.y < WINDOW_SIZE_Y)
	{
		p.x = -1;
		while (++p.x < WINDOW_SIZE_X)
		{
			color = ft_get_color((*fun)(app, f, &p));
			ft_put_pixel_img(app, &p, color);
		}
	}
}

double	ft_compute_julia(t_app *app, t_fractal *f, t_point *p)
{
	f->z.r = 1.0 * (p->x - WINDOW_SIZE_X / 2) /
		(0.5 * f->zoom * WINDOW_SIZE_X) + f->p1.x;
	f->z.i = (p->y - WINDOW_SIZE_Y / 2) /
		(0.5 * f->zoom * WINDOW_SIZE_Y) + f->p1.y;
	while ((f->z.r * f->z.r + f->z.i * f->z.i) < 4 && (f->i < f->i_max))
	{
		f->tmp = f->z.r;
		f->z.r = f->z.r * f->z.r - f->z.i * f->z.i + f->c.r;
		f->z.i = 2 * f->z.i * f->tmp + f->c.i;
		f->i += 1;
	}
	if (f->i < f->i_max)
	{
		f->zn = sqrt(f->z.r * f->z.r + f->z.i * f->z.i);
		f->c_index = f->i + 1 - (log(2) / f->zn) / log(2);
		return (f->c_index);
	}
}

void	ft_draw_fractal(t_app *app, char *name_fractal)
{
	t_fractal	*f;

	if (name_fractal == "julia")
	{
		f = ft_init_julia();
		ft_draw_img(app, f, ft_compute_julia(app, f, p));
	}
}
