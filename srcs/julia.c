/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 20:20:03 by daugier           #+#    #+#             */
/*   Updated: 2016/09/21 15:40:49 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_julia(t_struct *data)
{
	double	new_re;
	double	new_im;
	double	x;
	double	y;

	Y = -1;
	RE = 0.285 + L;
	IM = 0.01 + L / 10;
	while (++Y < HEIGHT)
	{
		X = -1;
		while (++X < WIDTH && (ITER = -1))
		{
			new_re = (X - POS_X - ((WIDTH + W) / 2)) * (4.0 / WIDTH) / ZOOM;
			new_im = (Y - POS_Y - ((HEIGHT + H) / 2)) * (4.0 / WIDTH) / ZOOM;
			while (((new_re * new_re + new_im * new_im) < 4) && ++ITER < MAXI)
			{
				x = new_re;
				y = new_im;
				new_re = x * x - y * y + RE;
				new_im = 2 * x * y + IM;
			}
			write_data_pixel(data);
		}
	}
}
