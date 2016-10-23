/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:33:16 by daugier           #+#    #+#             */
/*   Updated: 2016/10/23 02:40:38 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init_pos(t_struct *data)
{
	ZOOM = 1;
	COLORE = RED;
	H = 0;
	W = 0;
	POS_X = 0;
	POS_Y = 0;
	MAXI = 100;
	L = 0;
	X_MOOVE = 0;
	Y_MOOVE = 0;
}

t_struct		*ft_init_struct(char *av)
{
	t_struct	*data;

	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		exit(EXIT_FAILURE);
	ft_init_pos(data);
	NAME = ft_strdup(av);
	BPP = 24;
	ENDIAN = 1;
	WIDTH += 900;
	HEIGHT += 900;
	SIZE_LINE = WIDTH * (BPP / 8);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "Fractal");
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
	return (data);
}
