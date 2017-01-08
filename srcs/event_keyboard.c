/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:05:19 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/08 15:34:47 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_scale(int key, t_app *a)
{
	int		h_w;
	int		h_h;
	double	zr;

	h_w = WIN_W / 2;
	h_h = WIN_H / 2;
	zr = a->f->zoom * 10;
	if (key == KEY_KP_PLUS)
	{
		a->f->zoom *= 1.1;
		a->f->move.x += (h_h / h_w) / zr;
		a->f->move.y += (h_w / h_h) / zr;
	}
	else if (key == KEY_KP_MINUS)
	{
		a->f->zoom /= 1.1;
		a->f->move.x += (h_h / h_w) / zr;
		a->f->move.y += (h_w / h_h) / zr;
	}
}

static	void	ft_translate(int key, t_app *a)
{
	double	zr;

	zr = a->f->zoom * 20;
	if (key == KEY_UP)
		a->f->move.y += 10 / zr;
	else if (key == KEY_DOWN)
		a->f->move.y -= 10 / zr;
	else if (key == KEY_LEFT)
		a->f->move.x += 10 / zr;
	else if (key == KEY_RIGHT)
		a->f->move.x -= 10 / zr;
}

static void		ft_reset(int key, t_app *a)
{
	if (key == KEY_KP_DOT)
	{
		if(!ft_strcmp(a->f->name, "julia") ||
			!ft_strcmp(a->f->name, "mandelbrot") ||
			!ft_strcmp(a->f->name, "bship"))
			ft_init_fractal(a);
	}
}

static void		ft_mod_iter(int key, t_app *a)
{
	if (key == KEY_PAGE_UP)
		a->f->i_max += 10;
	else if (key == KEY_PAGE_DOWN)
		a->f->i_max = (a->f->i_max <= I_MIN) ? I_MIN : a->f->i_max - 10;
}

static void		ft_change_f(int key, t_app *a)
{
	if (key == KEY_KP_1)
		a->f = &a->tab_f[0];
	if (key == KEY_KP_2)
		a->f = &a->tab_f[1];
	if (key == KEY_KP_3)
		a->f = &a->tab_f[2];
}

int		ft_key_hook(int key, t_app *a)
{
	int	i;

	i = 0;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(a->mlx, a->win);
		free(a->tab_f);
		free(a);
		exit(EXIT_SUCCESS);
	}
	if (key == KEY_SPACE)
		a->f->stop_motion = a->f->stop_motion ? FALSE : TRUE;
	ft_translate(key, a);
	ft_scale(key, a);
	ft_reset(key, a);
	ft_mod_iter(key, a);
	ft_change_f(key, a);
	ft_draw_fractal(a);
	return (FALSE);
}
