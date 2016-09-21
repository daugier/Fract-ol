/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:10:22 by daugier           #+#    #+#             */
/*   Updated: 2016/09/21 01:43:59 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include <OpenCL/opencl.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>
# include "../libs/libft/includes/libft.h"

# define M data->m
# define H data->h
# define W data->w
# define Y_MOOVE data->y_moove
# define X_MOOVE data->x_moove
# define L data->l
# define IM data->c_im
# define RE data->c_re
# define POS_X data->pos_x
# define POS_Y data->pos_y
# define A data->a
# define H_PIC data->h_pic
# define W_PIC data->w_pic
# define NAME data->name
# define COLORE data->colore
# define ITER data->iter
# define MAXI data->imax
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
	int					m;
	int					h;
	int					w;
	int					y_moove;
	long double			l;
	int					x_moove;
	double				c_re;
	double				c_im;
	int					imax;
	double				pos_x;
	double				pos_y;
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
	long double			zoom;
}				t_struct;

int					mouse_motion(int x, int y, t_struct *data);
void				free_all(t_struct *data);
int					key_func(int keycode, t_struct *data);
int					mouse_func(int button, int x, int y, t_struct *data);
void				change_color(int keycode, t_struct *data);
void				draw_dodo(t_struct *data);
void				draw_sierpinski(t_struct *data);
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
