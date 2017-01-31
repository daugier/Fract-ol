/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 20:20:03 by daugier           #+#    #+#             */
/*   Updated: 2017/01/31 18:24:18 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		calc_julia(t_struct *data)
{
	double	x;
	double	y;

	x = NEW_RE;
	y = NEW_IM;
	NEW_RE = x * x - y * y + RE;
	NEW_IM = 2 * x * y + IM;
}

void		draw_julia(t_struct *data)
{
	Y = -1;
	if (!STAY)
	{
		RE = 0.285;
		IM = 0.01;
	}
	while (++Y < HEIGHT)
	{
		X = -1;
		while (++X < WIDTH && (ITER = -1))
		{
			NEW_RE = (X - POS_X - ((WIDTH + W) / 2)) * (4.0 / WIDTH) / ZOOM;
			NEW_IM = (Y - POS_Y - ((HEIGHT + H) / 2)) * (4.0 / WIDTH) / ZOOM;
			while (((NEW_RE * NEW_RE + NEW_IM * NEW_IM) < 4) && ++ITER < MAXI)
				calc_julia(data);
			write_data_pixel(data);
		}
	}
}
