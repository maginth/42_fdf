/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 18:01:52 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 19:47:57 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_raw_line_x(t_win win, t_pix p1, t_pix p2)
{
	t_rline	r;
	int		*pix;
	float	w;
	float	incr_w;

	r.s = (p1.y < p2.y) ? 1 : -1;
	incr_w = 1 / (float)(p2.x - p1.x);
	r.incr_d_a = r.s * (p1.y - p2.y);
	r.incr_d_b = r.incr_d_a + p2.x - p1.x;
	r.d = 0;
	w = 0;
	p2.x = p2.x >= win.width ? win.width - 1 : p2.x;
	while (p1.x <= p2.x)
	{
		pix = win.pix_start + p1.x++ + p1.y * win.width;
		if (p1.x > 0 && p1.x < win.width && p1.y > 0 && p1.y < win.height)
			*pix = interpol(p1.color, p2.color, w).i;
		w += incr_w;
		r.d += (r.d < 0 && (p1.y += r.s)) ? r.incr_d_b : r.incr_d_a;
	}
}

void		put_raw_line_y(t_win win, t_pix p1, t_pix p2)
{
	t_rline	r;
	int		*pix;
	float	w;
	float	incr_w;

	r.s = (p1.x < p2.x) ? 1 : -1;
	incr_w = 1 / (float)(p2.y - p1.y);
	r.incr_d_a = r.s * (p1.x - p2.x);
	r.incr_d_b = r.incr_d_a + p2.y - p1.y;
	r.d = 0;
	w = 0;
	p2.y = p2.y >= win.width ? win.width - 1 : p2.y;
	while (p1.y <= p2.y)
	{
		pix = win.pix_start + p1.x + p1.y++ * win.width;
		if (p1.x > 0 && p1.x < win.width && p1.y > 0 && p1.y < win.height)
			*pix = interpol(p1.color, p2.color, w).i;
		w += incr_w;
		r.d += (r.d < 0 && (p1.x += r.s)) ? r.incr_d_b : r.incr_d_a;
	}
}

int			ft_int_abs(int a)
{
	return (a < 0 ? -a : a);
}

void		put_raw_line(t_win win, t_pix p1, t_pix p2)
{
	if (ft_int_abs(p1.x - p2.x) > ft_int_abs(p1.y - p2.y))
	{
		if (p1.x < p2.x)
			put_raw_line_x(win, p1, p2);
		else
			put_raw_line_x(win, p2, p1);
	}
	else
	{
		if (p1.y < p2.y)
			put_raw_line_y(win, p1, p2);
		else
			put_raw_line_y(win, p2, p1);
	}
}
