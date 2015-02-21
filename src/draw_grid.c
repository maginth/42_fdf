/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 18:02:38 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 19:34:48 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	coef_shadow(t_point p1, t_point p2, t_point p3)
{
	t_point	v1;
	t_point v2;
	t_point v3;
	float	n;

	v1 = (t_point){p2.x - p1.x, p2.y - p1.y, p2.z - p1.z};
	v2 = (t_point){p3.x - p1.x, p3.y - p1.y, p3.z - p1.z};
	v3 = (t_point){v1.y * v2.z - v2.y * v1.z,
					v1.z * v2.x - v2.z * v1.x,
					v1.x * v2.y - v2.x * v1.y};
	n = ft_sqrt(v3.x * v3.x + v3.y * v3.y + v3.z * v3.z);
	return (0.5 + 0.5 * ft_abs(v3.z / n));
}

t_pix	pix_shadow(t_pix p, float x)
{
	static t_ucolor black = {.i = 0};

	p.color = interpol(black, p.color, x);
	return (p);
}

void	draw_one_shape(t_win *win, t_shape s, t_grid *grid, t_style *style)
{
	t_pix		*p;
	t_point		*pt;
	float		x;

	p = grid->pix;
	if (s.i3 < 0)
		limit_line(win, p[s.i1], p[s.i2], style);
	else
	{
		pt = grid->trans;
		x = coef_shadow(pt[s.i1], pt[s.i2], pt[s.i3]);
		if (style->fill_trgl)
		{
			style->fill_trgl(
				win,
				pix_shadow(p[s.i1], x),
				pix_shadow(p[s.i2], x),
				pix_shadow(p[s.i3], x));
		}
	}
}

void	draw_shapes(t_win *win, t_grid *grid, t_style *style)
{
	int				i;
	int				len;

	len = grid->shape_nb;
	quicksort(grid->trans, grid->shape, 0, len - 1);
	i = 0;
	while (i < len)
		draw_one_shape(win, grid->shape[i++], grid, style);
}

void	draw_grid(t_win *win, t_grid *grid, t_style *style, t_cam *cam)
{
	t_pix		*p;
	size_t		i;

	apply_trans(*cam, grid);
	if (style->color)
		apply_color(style->color, grid);
	style->proj(grid);
	if (style->put_pix)
	{
		i = grid->size;
		p = grid->pix;
		while (i--)
			style->put_pix(*win, *(p++));
	}
	if ((style->put_seg || style->fill_trgl) && grid->size > 2)
		draw_shapes(win, grid, style);
}
