/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 18:53:56 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 17:39:32 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float			calc1(t_vec v, t_point p)
{
	return (v.x * p.x + v.y * p.y + v.z * p.z + v.t);
}

void			apply_trans(t_cam c, t_grid *grid)
{
	t_point		*p;
	t_point		*o;
	size_t		i;

	o = grid->coordinate;
	p = grid->trans;
	i = grid->size;
	while (i--)
	{
		p->x = calc1(c.x, *o);
		p->y = calc1(c.y, *o);
		p->z = calc1(c.z, *o);
		p++;
		o++;
	}
}

t_ucolor		interpol(t_ucolor c2, t_ucolor c1, float x)
{
	t_ucolor	res;
	float		inv;

	inv = 1 - x;
	res.bt[0] = c1.bt[0] * x + c2.bt[0] * inv;
	res.bt[1] = c1.bt[1] * x + c2.bt[1] * inv;
	res.bt[2] = c1.bt[2] * x + c2.bt[2] * inv;
	return (res);
}

t_ucolor2		color_delta(t_ucolor c1, t_ucolor c2, int n)
{
	t_ucolor2	res;

	if (n == 0)
		n = 1;
	res.c.a.bt[0] = (c2.bt[0] - c1.bt[0]) / n;
	res.c.a.bt[1] = (c2.bt[1] - c1.bt[1]) / n;
	res.c.a.bt[2] = (c2.bt[2] - c1.bt[2]) / n;
	res.c.a.bt[3] = 0;
	res.c.b.bt[0] = 0xff & ((c2.bt[0] - c1.bt[0]) * 256 / n);
	res.c.b.bt[1] = 0xff & ((c2.bt[1] - c1.bt[1]) * 256 / n);
	res.c.b.bt[2] = 0xff & ((c2.bt[2] - c1.bt[2]) * 256 / n);
	res.c.b.bt[3] = 0;
	return (res);
}

void			apply_color(t_c_alti *colors, t_grid *grid)
{
	t_pix		*p;
	t_point		*o;
	t_c_alti	*colo;
	float		x;
	size_t		i;

	p = grid->pix;
	o = grid->coordinate;
	i = grid->size;
	while (i--)
	{
		colo = colors;
		while (o->z > colo->alti)
			colo++;
		if (colo->alti == INT_MAX || colo == colors)
			p->color = colo->c;
		else
		{
			x = (float)(o->z - colo[-1].alti)
				/ (float)(colo->alti - colo[-1].alti);
			p->color = interpol(colo[-1].c, colo->c, x);
		}
		p++;
		o++;
	}
}
