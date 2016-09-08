/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:54:21 by daugier           #+#    #+#             */
/*   Updated: 2016/09/08 20:19:27 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		free_all(t_struct *data)
{
	free(data);
	data = NULL;
}

static void		change_color(int keycode, t_struct *data)
{
	if (keycode == 18)
		COLOR = 0xFF0000;
	if (keycode == 19)
		COLOR = 0x00FF00;
	if (keycode == 20)
		COLOR = 0x0000FF;
	if (keycode == 21)
		COLOR = 0xFFFF00;
	if (keycode == 23)
		COLOR = 0x00FFFF;
	if (keycode == 22)
		COLOR = 0xFF00FF;
	if (keycode == 26)
		COLOR = 0xCccccc;
}

static int		key_func(int keycode, t_struct *data)
{
	ft_new_screen(data);
	change_color(keycode, data);
	if (keycode == 53)
	{
		free_all(data);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 116 || keycode == 121)
	{
		if (ZOOM - 2 > 0 && keycode == 121)
			ZOOM -= 2;
		else if (keycode == 116)
			ZOOM += 2;
	}
	if (keycode == 36)
		ft_init_pos(data);
	return (1);
}

int				main(int ac, char **av)
{
	t_struct		*data;

	if (ac != 2)
	{
		ft_putstr("Usage : ./fdf <fractal name>\n");
		exit(EXIT_FAILURE);
	}
	if (same_str(av[1], "Julia") || same_str(av[1], "Pyramide") ||
			same_str(av[1], "Mandelbrot"))
	{
		data = ft_init_struct(av[1]);
		ft_fdf(data, av[1]);
		mlx_key_hook(WIN, key_func, data);
		mlx_loop_hook(MLX, ft_fdf, data);
		mlx_loop(MLX);
		free_all(data);
		return (0);
	}
	ft_putstr("Fractal :\nJulia\nPyramide\nMandelbrot\n");
	return (0);
}
