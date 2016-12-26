/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:07:05 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/26 07:50:06 by amerej           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_arg(char *argv)
{
	if (ft_strcmp(argv, "julia") == FALSE ||
		ft_strcmp(argv, "mandelbrot") == FALSE ||
		ft_strcmp(argv, "sierpinski") == FALSE)
		return (TRUE);
	return (FALSE);
}

char		*ft_get_arg(char *argv)
{
	if (ft_check_arg(argv))
		return (argv);
	return (NULL);
}
