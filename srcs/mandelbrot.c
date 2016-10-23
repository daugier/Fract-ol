/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:21:11 by daugier           #+#    #+#             */
/*   Updated: 2016/10/19 16:33:51 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		calcul_re_im(t_struct *data)
{
	RE = ((Y - POS_Y - ((WIDTH + H) / 2.0)) * (4.0 / WIDTH) / ZOOM);
	IM = ((X - POS_X - ((HEIGHT + W) / 2.0)) * (4.0 / WIDTH) / ZOOM);
}

void			draw_mandelbrot(t_struct *data)
{
	double x;
	double y;
	double x_new;

	X = -1;
	while (++X < HEIGHT)
	{
		Y = -1;
		while (++Y < WIDTH && (ITER = -1))
		{
			calcul_re_im(data);
			y = 0;
			x = 0;
			while (x * x + y * y <= 4 && ++ITER < MAXI)
			{
				x_new = x * x - y * y + RE;
				y = 2 * x * y + IM;
				x = x_new;
			}
			write_data_pixel(data);
		}
	}
}
