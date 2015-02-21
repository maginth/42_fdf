/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:57:08 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 19:02:23 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		refresh_cam(t_cam *cam, t_view *v)
{
	float	cos_z;
	float	cos_h;
	float	sin_z;
	float	sin_h;
	float	z;
	float	p;
	float	a;

	z = v->zoom;
	p = v->perspec;
	a = z * v->alt_mult;
	cos_z = z * ft_cos(v->r_z);
	cos_h = ft_cos(v->r_h);
	sin_z = z * ft_sin(v->r_z);
	sin_h = ft_sin(v->r_h);
	*cam = (t_cam){(t_vec){cos_z, -sin_z, 0, v->t_v},
				  (t_vec){sin_z * cos_h, cos_z * cos_h, -a * sin_h, v->t_h},
				  (t_vec){sin_h * sin_z, cos_z * sin_h,
						  cos_h * a, v->t_p / p}};
}
