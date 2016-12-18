/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libg.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 01:29:29 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/16 14:09:52 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBG_H
# define LIBG_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../minilibx_osx/mlx.h"

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

t_env				*ft_init_env(int size_x, int size_y, char *title);
void				ft_draw_pixel_img(t_env *e, void *point, int color);

/*
**	macOS Keycode
*/

# define KEY_ESC 53

# define KEY_MOUSE_CLIC_L 1
# define KEY_MOUSE_CLIC_R 2
# define KEY_MOUSE_UP 5
# define KEY_MOUSE_DOWN 4
# define KEY_MOUSE_LEFT 7
# define KEY_MOUSE_RIGHT 6

# define KEY_0 29
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25

# define KEY_KP_DOT 65
# define KEY_KP_ENTER 76
# define KEY_KP_0 82
# define KEY_KP_1 83
# define KEY_KP_2 84
# define KEY_KP_3 85
# define KEY_KP_4 86
# define KEY_KP_5 87
# define KEY_KP_6 88
# define KEY_KP_7 89
# define KEY_KP_8 91
# define KEY_KP_9 92
# define KEY_KP_PLUS 69
# define KEY_KP_MINUS 78

# define KEY_PAGE_UP 116
# define KEY_PAGE_DOWN 121

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

/*
**	Ubuntu Keycode
*/
#endif
