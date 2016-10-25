/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:12:43 by daugier           #+#    #+#             */
/*   Updated: 2016/10/24 18:51:21 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		white_screen(t_struct *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < 50)
		{
			mlx_pixel_put(MLX, WIN, x, y, 0xFFA500);
		}
	}
}

void			ft_new_screen(t_struct *data)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
}

static void		write_color_screen(t_struct *data)
{
	mlx_string_put(MLX, WIN, 15, 5, 0x330000, "1");
	mlx_string_put(MLX, WIN, 40, 5, 0x660000, "2");
	mlx_string_put(MLX, WIN, 65, 5, 0x0000FF, "3");
	mlx_string_put(MLX, WIN, 90, 5, 0xC0C0C0, "4");
	mlx_string_put(MLX, WIN, 115, 5, 0x00FFFF, "5");
	mlx_string_put(MLX, WIN, 140, 5, 0xFFF00FF, "6");
	mlx_string_put(MLX, WIN, 165, 5, 0x000033, "7");
}

static void		write_data_screen(t_struct *data)
{
	char *s;

	s = ft_itoa(ZOOM);
	mlx_string_put(MLX, WIN, 15, 25, 0x6600FF, "zoom = ");
	mlx_string_put(MLX, WIN, 85, 25, 0x6600FF, s);
	mlx_string_put(MLX, WIN, 680, 25, 0x6600FF, "Fractal = ");
	mlx_string_put(MLX, WIN, 780, 25, 0x6600FF, NAME);
	free(s);
	s = NULL;
}

void			write_screen(t_struct *data)
{
	white_screen(data);
	write_color_screen(data);
	write_data_screen(data);
}
