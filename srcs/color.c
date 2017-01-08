/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:53:04 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/08 15:26:17 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_colorscheme(t_cscheme *cs)
{
	cs->freq[0] = 0.030;
	cs->freq[1] = 0.005;
	cs->freq[2] = 0.000;
	cs->amp[0] = 127;
	cs->amp[1] = 200;
	cs->amp[2] = 200;
	cs->phase[0] = 6;
	cs->phase[1] = 6;
	cs->phase[2] = 6;
	cs->center[0] = 55;
	cs->center[1] = 55;
	cs->center[2] = 55;
}

int				ft_get_color(double c_index, t_cscheme *cs)
{
	t_color		c;

	c.channels[0] = (unsigned char)(sin(cs->freq[0] * c_index + cs->phase[0])
		* cs->amp[0] + cs->center[0]);
	c.channels[1] = (unsigned char)(sin(cs->freq[1] * c_index + cs->phase[1])
		* cs->amp[1] + cs->center[1]);
	c.channels[2] = (unsigned char)(sin(cs->freq[2] * c_index + cs->phase[2])
		* cs->amp[2] + cs->center[2]);
	return (c.number);
}

void			ft_new_colorscheme(t_app *a)
{
	a->tab_f[0].cs = (t_cscheme *)malloc(sizeof(t_cscheme));
	a->tab_f[1].cs = (t_cscheme *)malloc(sizeof(t_cscheme));
	a->tab_f[2].cs = (t_cscheme *)malloc(sizeof(t_cscheme));
	ft_init_colorscheme(a->tab_f[0].cs);
	ft_init_colorscheme(a->tab_f[1].cs);
	ft_init_colorscheme(a->tab_f[2].cs);
}
