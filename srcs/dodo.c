/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dodo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 20:42:39 by daugier           #+#    #+#             */
/*   Updated: 2016/10/19 16:34:34 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_dodo(t_struct *data)
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
			RE = (X - POS_X - ((WIDTH + W) / 2.0)) * ((5.0 / WIDTH)) / ZOOM;
			IM = (Y - POS_Y - ((HEIGHT + H) / 2.0)) * ((5.0 / WIDTH)) / ZOOM;
			y = 0;
			x = 0;
			while (x * x + y * y <= 4 && ++ITER < MAXI)
			{
				x_new = x * x - y * y + RE;
				y = fabs(2 * x * y + IM);
				x = fabs(x_new);
			}
			write_data_pixel(data);
		}
	}
}
