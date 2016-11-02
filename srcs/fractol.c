/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 17:28:31 by daugier           #+#    #+#             */
/*   Updated: 2016/10/27 15:33:17 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	write_data_pixel(t_struct *data)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (ITER == 0)
		COLOR = COLORE / 1;
	else
		COLOR = COLORE / ITER * 10;
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
	else if (!ft_strcmp(NAME, "Dodo"))
		draw_dodo(data);
	else if (!ft_strcmp(NAME, "Julia"))
		draw_julia(data);
	else if (!ft_strcmp(NAME, "Sierpinski"))
		draw_sierpinski(data);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 50);
	write_screen(data);
	return (1);
}
