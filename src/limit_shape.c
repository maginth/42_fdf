/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:11:53 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/30 22:07:28 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		limit_pix(int limit, int side, t_lim l)
{
	if ((*l.a1 < limit) == side)
	{
		if ((*l.b1 < limit) == side)
			return (0);
		*l.a2 = *l.b2 + (*l.a2 - *l.b2) * (*l.b1 - limit) / (*l.b1 - *l.a1);
		*l.a1 = limit;
		return (2);
	}
	return (1);
}

static int		limit_bound(t_win *win, t_pix p1, t_pix p2)
{
	if (limit_pix(0, 1, (t_lim){&p1.x, &p1.y, &p2.x, &p2.y})
		&& limit_pix(win->width, 0, (t_lim){&p1.x, &p1.y, &p2.x, &p2.y})
		&& limit_pix(0, 1, (t_lim){&p1.y, &p1.x, &p2.y, &p2.x})
		&& limit_pix(win->height, 0, (t_lim){&p1.y, &p1.x, &p2.y, &p2.x}))
		return (1);
	return (0);
}

void			limit_line(t_win *win, t_pix p1, t_pix p2, t_style *style)
{
	if (style->put_seg)
	{
		if (limit_bound(win, p1, p2) && limit_bound(win, p2, p1))
			style->put_seg(*win, p1, p2);
	}
}

void			limit_horiz_line(t_win *win, t_pix p1, t_pix p2)
{
	int			*data;
	float		w;
	float		incr_w;

	data = win->pix_start;
	w = 0;
	incr_w = 1 / (float)(p2.x - p1.x);
	if (p1.y >= 0 && p1.y < win->height && p1.x < win->width)
	{
		p1.x = p1.x > 0 ? p1.x : 0;
		p2.x = p2.x > win->width ? win->width : p2.x;
		p1.y *= win->width;
		while (p1.x < p2.x)
		{
			data[p1.x++ + p1.y] = interpol(p1.color, p2.color, w).i;
			w += incr_w;
		}
	}
}
