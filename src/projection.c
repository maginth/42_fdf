/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:50:41 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 19:39:52 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			apply_perspect(t_grid *grid)
{
	t_point		*o;
	t_pix		*p;
	float		inv_z;
	size_t		i;
	float		perspec;

	o = grid->trans;
	p = grid->pix;
	i = grid->size;
	perspec = 1 / grid->view->perspec;
	while (i--)
	{
		if (o->z > 0)
		{
			inv_z = perspec / (float)o->z;
			p->x = (W_WIDTH * 0.5) + (o->x - (W_WIDTH * 0.5)) * inv_z;
			p++->y = (W_HEIGHT * 0.5) + (o++->y - (W_HEIGHT * 0.5)) * inv_z;
		}
		else
		{
			p->x = (o->x > 0) ? INT_MAX : INT_MIN;
			p++->y = (o++->y > 0) ? INT_MAX : INT_MIN;
		}
	}
}

void			apply_proj(t_grid *grid)
{
	t_point		*o;
	t_pix		*p;
	size_t		i;

	o = grid->trans;
	p = grid->pix;
	i = grid->size;
	while (i--)
	{
		p->x = o->x;
		p->y = o->y;
		p++;
		o++;
	}
}
