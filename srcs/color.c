/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:53:04 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/09 12:24:06 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_cscheme_tab(t_cscheme *t)
{
	t[0] = (t_cscheme){0.030, 0.005, 0.00, 6, 6, 6, 127, 200, 200, 55, 55, 55};
	t[1] = (t_cscheme){0.016, 0.013, 0.01, 4, 2, 1, 230, 230, 230, 25, 25, 25};
	t[2] = (t_cscheme){0.030, 0.020, 0.01, 1, 2, 1, 230, 230, 230, 25, 25, 25};
	t[3] = (t_cscheme){0.400, 0.200, 0.01, 4, 2, 1, 230, 230, 230, 25, 25, 25};
	t[4] = (t_cscheme){0.400, 0.400, 0.10, 6, 6, 6, 127, 200, 200, 55, 55, 55};
}

int				ft_get_color(double c_index, t_cscheme *cs)
{
	t_color		c;

	c.channels[0] = (unsigned char)(sin(cs->freq1 * c_index + cs->phase1)
		* cs->amp1 + cs->center1);
	c.channels[1] = (unsigned char)(sin(cs->freq2 * c_index + cs->phase2)
		* cs->amp2 + cs->center2);
	c.channels[2] = (unsigned char)(sin(cs->freq3 * c_index + cs->phase3)
		* cs->amp3 + cs->center3);
	return (c.number);
}

void			ft_new_cscheme_tab(t_app *a)
{
	a->tab_cs = (t_cscheme *)malloc(sizeof(t_cscheme) * 5);
	ft_init_cscheme_tab(a->tab_cs);
	a->cs = &a->tab_cs[0];
}

void			ft_change_color(int key, t_app *a)
{
	if (key == KEY_1)
		a->cs = &a->tab_cs[0];
	if (key == KEY_2)
		a->cs = &a->tab_cs[1];
	if (key == KEY_3)
		a->cs = &a->tab_cs[2];
	if (key == KEY_4)
		a->cs = &a->tab_cs[3];
	if (key == KEY_5)
		a->cs = &a->tab_cs[4];
}
