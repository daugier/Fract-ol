/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:12:43 by daugier           #+#    #+#             */
/*   Updated: 2017/01/31 18:32:10 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_new_screen(t_struct *data)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN);
}

static void		write_info_screen(t_struct *data)
{
	mlx_string_put(MLX, WIN, (WIDTH / 2) - 155, 5, 0x00FF00,
		"Touches disponibles");
	mlx_string_put(MLX, WIN, 20, 25, 0x0000CD, "J   -> Julia");
	mlx_string_put(MLX, WIN, 20, 40, 0x0000CD, "M   -> Mandelbrot");
	mlx_string_put(MLX, WIN, 20, 55, 0x0000CD, "D   -> Dodo");
	mlx_string_put(MLX, WIN, 20, 70, 0x0000CD, "S   -> Sierpinski");
	mlx_string_put(MLX, WIN, (WIDTH / 2) - 170, 25, 0x0000CD,
			"Fleche gauche -> Gauche");
	mlx_string_put(MLX, WIN, (WIDTH / 2) - 170, 40, 0x0000CD,
			"Fleche droite -> Droite");
	mlx_string_put(MLX, WIN, (WIDTH / 2) - 170, 55, 0x0000CD,
			"Fleche bas    -> Bas");
	mlx_string_put(MLX, WIN, (WIDTH / 2) - 170, 70, 0x0000CD,
			"Fleche haut   -> Haut");
	mlx_string_put(MLX, WIN, (WIDTH - 335), 25, 0x0000CD,
			"De 1 a 7              -> Couleur");
	mlx_string_put(MLX, WIN, (WIDTH - 335), 40, 0x0000CD,
			"Page up / Molette     -> Zoomer");
	mlx_string_put(MLX, WIN, (WIDTH - 335), 55, 0x0000CD,
			"Page down / Molette   -> Dezoomer");
	mlx_string_put(MLX, WIN, (WIDTH - 335), 70, 0x0000CD,
			"Entrer                -> Reset");
}

static void		write_data_screen(t_struct *data)
{
	mlx_string_put(MLX, WIN, 680, HEIGHT - 25, 0x6600FF, "Fractale =");
	mlx_string_put(MLX, WIN, 785, HEIGHT - 25, 0x6600FF, NAME);
	if (ft_strcmp(NAME, "Julia") == 0)
	{
		mlx_string_put(MLX, WIN, ((WIDTH / 2) - 150), HEIGHT - 25, 0x00bfff,
			"Press X for Moove or Stop Julia");
	}
}

void			write_screen(t_struct *data)
{
	write_info_screen(data);
	write_data_screen(data);
}
