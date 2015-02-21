/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 23:36:46 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 19:49:09 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bubble(float *a, float *b)
{
	float	tmp;

	if (*a < *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

float	max_z(t_point *p, t_shape s)
{
	float	a;
	float	b;
	float	c;

	a = p[s.i1].z;
	b = p[s.i2].z;
	if (s.i3 < 0)
		return (a + b);
	c = p[s.i3].z;
	bubble(&a, &b);
	bubble(&b, &c);
	bubble(&a, &b);
	return (a + c);
}

void	quicksort(t_point *p, t_shape *shape, int start, int end)
{
	int			i;
	int			j;
	t_shape		tmp;
	float		pivot_z;

	if (start >= end)
		return ;
	i = start;
	j = end;
	pivot_z = max_z(p, shape[(start + end) / 2]);
	while (i < j)
	{
		while (max_z(p, shape[i]) > pivot_z)
			i++;
		while (max_z(p, shape[j]) <= pivot_z && i < j)
			j--;
		tmp = shape[i];
		shape[i++] = shape[j];
		shape[j--] = tmp;
	}
	quicksort(p, shape, start, i - 2);
	quicksort(p, shape, i, end);
}
