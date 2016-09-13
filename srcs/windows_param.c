/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:12:43 by daugier           #+#    #+#             */
/*   Updated: 2016/09/13 18:28:33 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		write_color_screen(t_struct *data)
{
	mlx_string_put(MLX, WIN, 5, 0, 0xFF0000, "1");
	mlx_string_put(MLX, WIN, 20, 0, 0x00FF00, "2");
	mlx_string_put(MLX, WIN, 35, 0, 0x0000FF, "3");
	mlx_string_put(MLX, WIN, 50, 0, 0xFFFF00, "4");
	mlx_string_put(MLX, WIN, 65, 0, 0x00FFFF, "5");
	mlx_string_put(MLX, WIN, 80, 0, 0xFFF00FF, "6");
	mlx_string_put(MLX, WIN, 95, 0, 0xFFFFFF, "7");
}

static void		write_data_screen(t_struct *data)
{
	mlx_string_put(MLX, WIN, 5, 25, 0xcccccc, "x    = ");
	mlx_string_put(MLX, WIN, 70, 25, 0xcccccc, ft_itoa(X));
	mlx_string_put(MLX, WIN, 5, 40, 0xcccccc, "y    = ");
	mlx_string_put(MLX, WIN, 70, 40, 0xcccccc, ft_itoa(Y));
	mlx_string_put(MLX, WIN, 5, 55, 0xcccccc, "zoom = ");
	mlx_string_put(MLX, WIN, 70, 55, 0xcccccc, ft_itoa(ZOOM));
}

void			write_screen(t_struct *data)
{
	write_color_screen(data);
	write_data_screen(data);
}

void			ft_new_screen(t_struct *data)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
}
