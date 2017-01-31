/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:54:21 by daugier           #+#    #+#             */
/*   Updated: 2016/11/02 10:33:24 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				quit_func(t_struct *data)
{
	free_all(data);
	exit(EXIT_FAILURE);
	return (1);
}

static int		check_name(char *av)
{
	if (!ft_strcmp(av, "Julia") || !ft_strcmp(av, "Dodo") ||
		!ft_strcmp(av, "Mandelbrot") || !ft_strcmp(av, "Sierpinski"))
		return (1);
	return (0);
}

void			free_all(t_struct *data)
{
	mlx_destroy_image(MLX, IMG);
	MLX = NULL;
	WIN = NULL;
	IMG = NULL;
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
		ft_putstr("Usage : ./fractol <fractal name>\n");
		exit(EXIT_FAILURE);
	}
	if (check_name(av[1]))
	{
		data = ft_init_struct(av[1]);
		fractol(data);
		mlx_loop_hook(MLX, fractol, data);
		mlx_hook(WIN, 17, ButtonMotionMask, quit_func, data);
		mlx_hook(WIN, KeyPress, KeyPressMask, key_func, data);
		mlx_hook(WIN, ButtonPress, ButtonPressMask, mouse_func, data);
		mlx_hook(WIN, MotionNotify, ButtonMotionMask, mouse_motion, data);
		mlx_loop(MLX);
	}
	else
		ft_putstr("Fractal :\nJulia\nSierpinski\nMandelbrot\nDodo\n");
	return (0);
}
