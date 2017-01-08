/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:53:04 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/08 19:36:20 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_cscheme_tab(t_cscheme *t)
{
	t[0] = (t_cscheme){0.03, 0.005, 0.00, 6, 6, 6, 127, 200, 200, 55, 55, 55};
	t[1] = (t_cscheme){0.34, 0.185, 0.15, 6, 6, 6, 197, 210, 210, 55, 55, 55};
	t[2] = (t_cscheme){0.31, 0.155, 0.21, 14, 7, 10, 197, 180, 230, 55, 75, 80};
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
	a->tab_cs = (t_cscheme *)malloc(sizeof(t_cscheme) * 3);
	ft_init_cscheme_tab(a->tab_cs);
	a->cs = &a->tab_cs[0];
}
