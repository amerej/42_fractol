/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libg.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 01:29:29 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/26 07:17:04 by amerej           ###   ########.fr       */
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

typedef struct		s_image
{
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;
#endif
