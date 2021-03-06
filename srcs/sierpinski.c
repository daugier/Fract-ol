/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 23:59:16 by daugier           #+#    #+#             */
/*   Updated: 2016/10/23 03:09:32 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_sierpinski(t_struct *data)
{
	ITER = 50;
	Y = -1;
	while (++Y < HEIGHT)
	{
		X = -1;
		while (++X < WIDTH && (ITER = -1))
		{
			IM = fabsl((X - POS_X - (((HEIGHT + (W * 1000)) / 2)) *
						(4.0 / WIDTH)));
			RE = fabsl((Y - POS_Y - (((HEIGHT + (H * 1000)) / 2)) *
						(4.0 / WIDTH)));
			while (((int)IM % 3 != 1 || ((int)RE % 3) != 1) && ++ITER < MAXI)
			{
				IM /= 3;
				RE /= 3;
			}
			if (ITER != MAXI)
				ITER = 1;
			write_data_pixel(data);
		}
	}
}
