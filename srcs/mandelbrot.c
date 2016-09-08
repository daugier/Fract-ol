/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:21:11 by daugier           #+#    #+#             */
/*   Updated: 2016/09/08 20:22:18 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_mandelbrot(t_struct *data)
{
	double x;
	double y;
	double c_re;
	double c_im;
	double x_new;

	X = -1;
	while (++X < HEIGHT)
	{
		Y = -1;
		while (++Y < WIDTH && (ITER = -1))
		{
			c_re = ZOOM * ((Y - WIDTH / 2.0) * 4.0 / WIDTH);
			c_im = ZOOM * ((X - HEIGHT / 2.0) * 4.0 / WIDTH);
			y = 0;
			x = 0;
			while (x * x + y * y <= 4 && ++ITER < MAXI)
			{
				x_new = x * x - y * y + c_re;
				y = 2 * x * y + c_im;
				x = x_new;
			}
			write_data_pixel(data);
		}
	}
}
