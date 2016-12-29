/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:07:05 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/29 13:32:17 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_user_input(char *argv)
{
	if (ft_strcmp(argv, "julia") == FALSE ||
		ft_strcmp(argv, "mandelbrot") == FALSE ||
		ft_strcmp(argv, "bship") == FALSE)
		return (TRUE);
	return (FALSE);
}

char		*ft_get_user_input(char *argv)
{
	if (ft_check_user_input(argv))
		return (argv);
	return (NULL);
}
