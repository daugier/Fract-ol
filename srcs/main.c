/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:54:21 by daugier           #+#    #+#             */
/*   Updated: 2016/09/13 21:08:32 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		moove_map(int keycode, t_struct *data)
{
	if (keycode == 126 || keycode == 125)
		H_PIC += keycode == 126 ? -30 : 30;
	if (keycode == 123 || keycode == 124)
		W_PIC += keycode == 124 ? 30 : -30;
	if (keycode == 67 || keycode == 75)
	{
		if (A - 0.4 > 0.4 && keycode == 75)
			A += -0.4;
		else if (keycode == 67)
			A += 0.4;
	}
}

static int		check_name (char *av)
{
	if (!ft_strcmp(av, "Julia") || !ft_strcmp(av, "Brain") ||
		!ft_strcmp(av, "Mandelbrot") || !ft_strcmp(av, "Pyramide"))
		return (1);
	return (0);
}

static void		free_all(t_struct *data)
{
	free(NAME);
	NAME = NULL;
	free(data);
	data = NULL;
}

static void		change_color(int keycode, t_struct *data)
{
	if (keycode == 18)
		COLORE = 0xFF0000;
	if (keycode == 19)
		COLORE = 0x00FF00;
	if (keycode == 20)
		COLORE = 0x0000FF;
	if (keycode == 21)
		COLORE = 0xFFFF00;
	if (keycode == 23)
		COLORE = 0x00FFFF;
	if (keycode == 22)
		COLORE = 0xFF00FF;
	if (keycode == 26)
		COLORE = 0xCccccc + 0xFF0000;
}

static int		key_func(int keycode, t_struct *data)
{
	ft_new_screen(data);
	change_color(keycode, data);
	moove_map(keycode, data);
	if (keycode == 53)
	{
		free_all(data);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 116 || keycode == 121)
	{
		if (ZOOM + 0.1 > 0 && keycode == 116)
			ZOOM -= 0.1;
		else if (keycode == 121)
			ZOOM += 0.1;
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
	if (check_name(av[1]))
	{
		data = ft_init_struct(av[1]);
		fractol(data);
		mlx_loop_hook(MLX, fractol, data);
		mlx_key_hook(WIN, key_func, data);
		mlx_loop(MLX);
		free_all(data);
	}
	else
		ft_putstr("Fractal :\nJulia\nPyramide\nMandelbrot\nBrain\n");
	return (0);
}
