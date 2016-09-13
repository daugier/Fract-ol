/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 20:20:03 by daugier           #+#    #+#             */
/*   Updated: 2016/09/09 16:06:46 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_julia(t_struct *data)
{
	double	c_re;
	double	c_im;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;

	Y = -1;
	c_re = 0.285;
	c_im = 0.01;
	while (++Y < HEIGHT)
	{
		X = -1;
		while (++X < WIDTH && (ITER = -1))
		{
			new_re = 1.5 * (X - WIDTH / 2) / (0.5 * ZOOM * WIDTH / 1.25);
			new_im = (Y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT / 1.25);
			while (((new_re * new_re + new_im * new_im) < 4) && ++ITER < MAXI)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im + c_re;
				new_im = 2 * old_re * old_im + c_im;
			}
			write_data_pixel(data);
		}
	}
}
