/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:10:22 by daugier           #+#    #+#             */
/*   Updated: 2016/09/13 20:51:11 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "../libft/includes/libft.h"

# define A data->a
# define H_PIC data->h_pic
# define W_PIC data->w_pic
# define NAME data->name
# define COLORE data->colore
# define ITER data->iter
# define MAXI 100
# define X data->x
# define Y data->y
# define ZOOM data->zoom
# define MLX data->mlx
# define WIN data->win
# define IMG data->img
# define BPP data->bit_per_pixel
# define COLOR data->color_value
# define PUT_IMG data->mlx_put_img
# define ENDIAN data->endian
# define SIZE_LINE data->size_line
# define DATA data->data
# define HEIGHT data->height
# define WIDTH data->width

typedef struct	s_struct
{
	double				a;
	int					h_pic;
	int					w_pic;
	char				*name;
	int					colore;
	int					iter;
	int					x;
	int					iteration;
	int					y;
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					size_line;
	unsigned long int	color_value;
	int					mlx_put_img;
	int					endian;
	int					bit_per_pixel;
	int					width;
	int					height;
	double					zoom;
}				t_struct;

void				draw_brain(t_struct *data);
void				draw_pyramide(t_struct *data);
void				draw_julia(t_struct *data);
void				define_color(t_struct *data);
void				draw_mandelbrot(t_struct *data);
void				write_screen(t_struct *data);
void				write_data_pixel(t_struct *data);
void				ft_init_pos(t_struct *data);
t_struct			*ft_init_struct(char *av);
int					fractol(t_struct *data);
void				ft_new_screen(t_struct *data);

#endif
