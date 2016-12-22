/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libg.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 01:29:29 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/22 02:15:12 by amerej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBG_H
# define LIBG_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../minilibx_osx/mlx.h"
# include "keycode_osx.h"

typedef struct		s_point_i
{
	int				x;
	int				y;
}					t_point_i;

typedef struct		s_point_d
{
	double			x;
	double			y;
}					t_point_d;

typedef struct		s_point_ld
{
	long double		x;
	long double		y;
}					t_point_ld;

typedef struct		s_image
{
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_image			*img
}					t_env;

t_env				*ft_new_window(int size_x, int size_y, char *title);
void				ft_put_pixel_img(t_env *e, void *point, int color);
#endif
