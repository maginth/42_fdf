/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:25:40 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 18:34:16 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

static const float	g_pi = 3.14159265358979;

float				ft_abs(float x)
{
	return (x < 0 ? -x : x);
}

float				ft_mod(float a, float b)
{
	int		k;

	k = a / b;
	return (a - k * b);
}

float				ft_cos(float x)
{
	float	sgn;
	float	x2;
	float	x4;
	float	x8;

	x = ft_mod(ft_abs(x), 2 * g_pi);
	if (x > g_pi)
		x = 2 * g_pi - x;
	sgn = x > (g_pi / 2);
	if (sgn)
		x = g_pi - x;
	x2 = x * x;
	x4 = x2 * x2;
	x8 = x4 * x4;
	x = 1 - x2 / 2 + x4 / 24 - x4 * x2 / 720 + x8 / 40320 - x8 * x2 / 3628800
			+ x8 * x4 / 479001600;
	if (sgn)
		return (-x);
	return (x);
}

float				ft_sin(float x)
{
	return (ft_cos(x - g_pi / 2));
}

float				ft_sqrt(float x)
{
	float	r;
	int		i;

	r = 1;
	i = 30;
	while (i--)
	{
		r = (r + x / r) / 2;
	}
	return (r);
}
