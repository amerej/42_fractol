/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_user_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:07:05 by aditsch           #+#    #+#             */
/*   Updated: 2016/12/21 14:56:53 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_check_arg(char *argv)
{
	if (ft_strcmp(argv, "julia") == FALSE ||
		ft_strcmp(argv, "mandelbrot") == FALSE ||
		ft_strcmp(argv, "sierpinski") == FALSE)
		return (TRUE);
	return (FALSE);
}

char	*ft_get_arg(int argc, char *argv[])
{
	if (ft_check_arg(argv[argc]))
		return (argv[argc]);
	return (NULL);
}

int		ft_check_usage_error(int argc, char *argv[])
{
	if (argc == 2 && ft_get_arg(1, argv) != NULL)
		return (TRUE);
	return (FALSE);
}
