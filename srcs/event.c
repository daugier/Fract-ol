/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 00:05:24 by daugier           #+#    #+#             */
/*   Updated: 2016/10/23 02:40:37 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_func(int button, int x, int y, t_struct *data)
{
	if (button == 4 && ZOOM / 1.5 > 0)
	{
		if (MAXI > 100)
			MAXI -= 5;
		ZOOM /= 1.5;
		POS_X = (WIDTH / 2) - x + POS_X / 1.5;
		POS_Y = (HEIGHT / 2) - y + POS_Y / 1.5;
	}
	if (button == 5 && ZOOM * 1.5 <= 1234648375)
	{
		MAXI += 5;
		ZOOM *= 1.5;
		POS_X = (WIDTH / 2) - x + POS_X * 1.5;
		POS_Y = (HEIGHT / 2) - y + POS_Y * 1.5;
	}
	return (1);
}

void		change_color(int keycode, t_struct *data)
{
	if (keycode == 18)
		COLORE = RED;
	if (keycode == 19)
		COLORE = DARKKHAKI;
	if (keycode == 20)
		COLORE = GREEN;
	if (keycode == 21)
		COLORE = ORANGE;
	if (keycode == 23)
		COLORE = GRAY;
	if (keycode == 22)
		COLORE = GOLDENROD;
	if (keycode == 26)
		COLORE = MAROON;
}

static int	key_func_bis(int keycode, t_struct *data)
{
	if (keycode > 82 && keycode < 87)
	{
		free(NAME);
		NAME = NULL;
	}
	if (keycode == 83 || keycode == 84)
		NAME = ft_strdup("Mandelbrot");
	if (keycode == 84)
		NAME = ft_strdup("Julia");
	if (keycode == 85)
		NAME = ft_strdup("Sierpinski");
	if (keycode == 86)
		NAME = ft_strdup("Dodo");
	if (keycode == 116 && ZOOM * 1.5 <= 1234648375)
	{
		MAXI += 3;
		ZOOM *= 1.5;
	}
	if (keycode == 121 && ZOOM / 1.5 > 0)
	{
		MAXI -= 3;
		ZOOM /= 1.5;
	}
	return (1);
}

int			key_func(int keycode, t_struct *data)
{
	ft_new_screen(data);
	change_color(keycode, data);
	key_func_bis(keycode, data);
	if (keycode == 53)
	{
		free_all(data);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 36 || keycode == 84 || keycode == 85 || keycode == 86
		|| keycode == 83)
		ft_init_pos(data);
	if (keycode == 7)
		X_MOOVE == 1 ? X_MOOVE-- : X_MOOVE++;
	if (keycode == 16)
		Y_MOOVE == 1 ? Y_MOOVE-- : Y_MOOVE++;
	if (keycode == 126 || keycode == 125)
		H += keycode == 126 ? -30 - ZOOM * 30 : 30 + ZOOM * 30;
	if (keycode == 123 || keycode == 124)
		W += keycode == 124 ? 30 + ZOOM * 30 : -30 - ZOOM * 30;
	return (1);
}

int			mouse_motion(int x, int y, t_struct *data)
{
	if (X_MOOVE)
	{
		RE = (float)(x + 550 - WIDTH) / 200;
		IM = (float)(y + 450 - HEIGHT) / 300;
	}
	return (1);
}
