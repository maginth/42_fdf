/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 16:01:03 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/27 16:51:40 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pix	proj_horiz(int y, t_pix p1, t_pix p2)
{
	t_pix	res;
	float	w;

	w = (float)(p1.y - y) / (float)(p1.y - p2.y);
	res.y = y;
	res.x = p1.x + (p2.x - p1.x) * w;
	res.color = interpol(p1.color, p2.color, w);
	return (res);
}

static void		raw_triangle(t_win *win, t_pix p1, t_pix p2, t_pix p3)
{
	int			y;
	int			end;
	t_pix		a;
	t_pix		b;

	y = p1.y < 0 ? 0 : p1.y;
	end = p3.y > win->height ? win->height : p3.y;
	while (y < end)
	{
		a = proj_horiz(y, p1, p3);
		if (y < p2.y)
			b = proj_horiz(y, p1, p2);
		else
			b = proj_horiz(y, p2, p3);
		if (a.x < b.x)
			limit_horiz_line(win, a, b);
		else
			limit_horiz_line(win, b, a);
		y++;
	}
}

static void		bulle(int bool, t_pix *p1, t_pix *p2)
{
	t_pix	tmp;

	if (bool)
		return ;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void			put_raw_triangle(t_win *win, t_pix p1, t_pix p2, t_pix p3)
{
	bulle(p1.y < p2.y, &p1, &p2);
	bulle(p1.y < p3.y, &p1, &p3);
	bulle(p2.y < p3.y, &p2, &p3);
	raw_triangle(win, p1, p2, p3);
}
