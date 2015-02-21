/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 10:36:15 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/28 12:00:27 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "win.h"

void			close_win(t_win *win)
{
	mlx_destroy_window(g_mlx_core, win->mlx_win);
	free(win);
	g_win_count--;
	if (g_win_count <= 0)
		exit(0);
}