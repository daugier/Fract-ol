/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:54:21 by daugier           #+#    #+#             */
/*   Updated: 2016/09/21 15:29:44 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		check_name(char *av)
{
	if (!ft_strcmp(av, "Julia") || !ft_strcmp(av, "Dodo") ||
		!ft_strcmp(av, "Mandelbrot") || !ft_strcmp(av, "Sierpinski"))
		return (1);
	return (0);
}

void			free_all(t_struct *data)
{
	free(NAME);
	NAME = NULL;
	free(data);
	data = NULL;
}

int				main(int ac, char **av)
{
	t_struct		*data;

	if (ac != 2)
	{
		ft_putstr("Usage : ./fdf <fractal name>\n");
		exit(EXIT_FAILURE);
	}
	if (check_name(av[1]))
	{
		data = ft_init_struct(av[1]);
		fractol(data);
		mlx_loop_hook(MLX, fractol, data);
		mlx_hook(WIN, KeyPress, KeyPressMask, key_func, data);
		mlx_hook(WIN, ButtonPress, ButtonPressMask, mouse_func, data);
		mlx_hook(WIN, MotionNotify, ButtonMotionMask, mouse_motion, data);
		mlx_loop(MLX);
		free_all(data);
	}
	else
		ft_putstr("Fractal :\nJulia\nSierpinski\nMandelbrot\nDodo\n");
	return (0);
}
