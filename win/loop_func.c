/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:16:51 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/27 12:35:07 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "win.h"

void			loop_func(int (*func)(void *), void *param)
{
	if (!g_mlx_core)
	{
		if (!(g_mlx_core = mlx_init()))
			exit(EXIT_FAILURE);
	}
	if (func)
		mlx_loop_hook(g_mlx_core, func, param);
	mlx_loop(g_mlx_core);
}