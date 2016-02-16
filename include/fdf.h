/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:23:28 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 19:47:03 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/mlx.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include "ft_math.h"
# include "../win/win.h"
# define AFFICH_MOD 4
# define MAX_POINT 100000
# define W_WIDTH 1280
# define W_HEIGHT 960
# define NEW_LINE (short)0x8000

typedef struct			s_view
{
	float				r_z;
	float				r_h;
	float				zoom;
	float				perspec;
	float				alt_mult;
	float				t_h;
	float				t_v;
	float				t_p;
	int					affich_mod;
}						t_view;

typedef struct			s_rline
{
	int					s;
	int					incr_d_a;
	int					incr_d_b;
	int					d;
}						t_rline;

typedef struct			s_point
{
	float				x;
	float				y;
	float				z;
}						t_point;

typedef union			u_ucolor
{
	unsigned char		bt[4];
	int					i;
}						t_ucolor;

typedef struct			s_ucolor2s
{
	t_ucolor			a;
	t_ucolor			b;
}						t_ucolor2s;

typedef union			s_ucolor2
{
	t_ucolor2s			c;
	long				l;
}						t_ucolor2;

typedef struct			s_c_alti
{
	t_ucolor			c;
	int					alti;
}						t_c_alti;

typedef struct			s_vec
{
	float				x;
	float				y;
	float				z;
	float				t;
}						t_vec;

typedef struct			s_cam
{
	t_vec				x;
	t_vec				y;
	t_vec				z;
}						t_cam;

typedef struct			s_lim
{
	int					*a1;
	int					*a2;
	int					*b1;
	int					*b2;
}						t_lim;

typedef struct			s_pix
{
	int					x;
	int					y;
	t_ucolor			color;
}						t_pix;
/*
** i1, i2, i3 are index of point in the pixel array
*/
typedef struct			s_shape
{
	int					i1;
	int					i2;
	int					i3;
}						t_shape;

typedef struct			s_grid
{
	t_point				*coordinate;
	t_point				*trans;
	t_view				*view;
	t_pix				*pix;
	t_shape				*shape;
	size_t				size;
	int					shape_nb;
}						t_grid;

typedef struct			s_style
{
	void				(*proj)(t_grid*);
	void				(*put_pix)(t_win, t_pix);
	void				(*put_seg)(t_win, t_pix, t_pix);
	void				(*fill_trgl)(t_win*, t_pix, t_pix, t_pix);
	t_c_alti			*color;
}						t_style;

typedef struct			s_refresh
{
	t_win				*win;
	t_grid				*grid;
	t_style				*style;
	t_cam				*cam;
	t_view				*view;
}						t_refresh;

/*
** window utilities
*/
int						loop_key(void *param);
void					change_mod(t_win *win, void* param);
/*
** create style and cam view
*/
int						refresh(void *param);
void					refresh_cam(t_cam *cam, t_view *v);
t_style					*create_style(t_c_alti color[]);
t_cam					*create_cam(t_point p, t_point dir,
									float rotation, float persp);
/*
** geometric operations
*/
t_ucolor				interpol(t_ucolor c2, t_ucolor c1, float x);
t_ucolor2				color_delta(t_ucolor c1, t_ucolor c2, int n);
void					apply_trans(t_cam c, t_grid *grid);
void					apply_color(t_c_alti *color, t_grid *grid);
void					apply_perspect(t_grid *grid);
void					apply_proj(t_grid *grid);
/*
** calc pix position and draw the grid on screen
*/
void					quicksort(t_point *p, t_shape *shape,
								int start, int end);
void					draw_grid(t_win *win, t_grid *grid,
									t_style *style, t_cam *cam);
/*
** put functions to draw shapes on the window
*/
void					limit_line(t_win *win, t_pix p1,
								t_pix p2, t_style *style);
void					limit_horiz_line(t_win *win, t_pix p1, t_pix p2);
void					put_simple_pix(t_win win, t_pix p);
void					put_raw_line(t_win win, t_pix p1, t_pix p2);
void					put_raw_triangle(t_win *win, t_pix p1,
										t_pix p2, t_pix p3);
/*
** file analyse
*/
void					*destruct_grid(t_grid *grid);
t_grid					*make_grid(short *buf, int size);
t_grid					*read_file(int fd);

#endif
