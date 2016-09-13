/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 17:28:31 by daugier           #+#    #+#             */
/*   Updated: 2016/09/13 21:08:17 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	define_color(t_struct *data)
{
	if (ITER > 0 && ITER < 10)
		COLOR = 0x000000;
	else if (ITER > 10 && ITER < 20)
		COLOR = 0x000033;
	else if (ITER > 20 && ITER < 30)
		COLOR = 0x000066;
	else if (ITER > 30 && ITER < 40)
		COLOR = 0x000099;
	else if (ITER > 40 && ITER < 50)
		COLOR = 0x0000CC;
	else if (ITER > 50 && ITER < 60)
		COLOR = 0x0000FF;
	else if (ITER > 60 && ITER < 70)
		COLOR = 0x3300FF;
	else if (ITER > 70 && ITER < 80)
		COLOR = 0x3300CC;
	else if (ITER > 80 && ITER < 90)
		COLOR = 0x330099;
	else if (ITER > 90 && ITER < 100)
		COLOR = 0x330066;
	else
		COLOR = 0x000066;
}

void	write_data_pixel(t_struct *data)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	define_color(data);
	COLOR += COLORE;
	b = (COLOR & 0xFF0000) >> 16;
	g = (COLOR & 0xFF00) >> 8;
	r = (COLOR & 0xFF);
	if (X >= 0 && Y >= 0 && X < WIDTH && Y < HEIGHT)
	{
		DATA[Y * SIZE_LINE + X * (BPP / 8)] = r;
		DATA[Y * SIZE_LINE + X * (BPP / 8) + 1] = g;
		DATA[Y * SIZE_LINE + X * (BPP / 8) + 2] = b;
	}
}

int		fractol(t_struct *data)
{
	 if (!ft_strcmp(NAME, "Mandelbrot"))
		draw_mandelbrot(data);
	else if (!ft_strcmp(NAME, "Brain"))
		draw_brain(data);
	else if (!ft_strcmp(NAME, "Julia"))
		draw_julia(data);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	write_screen(data);
	return (1);
}
