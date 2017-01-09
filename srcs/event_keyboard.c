/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:05:19 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/09 12:19:30 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		ft_init_fractal_tab(a->tab_f);
}

static void		ft_mod_iter(int key, t_app *a)
{
	if (key == KEY_PAGE_UP)
		a->f->i_max += 10;
	else if (key == KEY_PAGE_DOWN)
		a->f->i_max = (a->f->i_max <= I_MIN) ? I_MIN : a->f->i_max - 10;
}

static void		ft_change_fractal(int key, t_app *a)
{
	if (key == KEY_KP_1)
		a->f = &a->tab_f[0];
	if (key == KEY_KP_2)
		a->f = &a->tab_f[1];
	if (key == KEY_KP_3)
		a->f = &a->tab_f[2];
	if (key == KEY_KP_4)
		a->f = &a->tab_f[3];
	if (key == KEY_KP_5)
		a->f = &a->tab_f[4];
}

int				ft_key_hook(int key, t_app *a)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(a->mlx, a->win);
		free(a->tab_f);
		free(a->tab_cs);
		free(a);
		exit(EXIT_SUCCESS);
	}
	if (key == KEY_SPACE)
		a->f->stop_motion = a->f->stop_motion ? FALSE : TRUE;
	ft_translate(key, a);
	ft_reset(key, a);
	ft_mod_iter(key, a);
	ft_change_fractal(key, a);
	ft_change_color(key, a);
	ft_draw_fractal(a);
	return (FALSE);
}
