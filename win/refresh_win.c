/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 10:36:15 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/27 13:45:32 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "win.h"

int				refresh_win(t_win *win)
{
	void*	tmp;
	int*	itmp;

	tmp = win->img;
	itmp = win->pix_start;
	win->pix_start = win->pix_start2;
	win->img = win->img2;
	win->pix_end = win->pix_start + win->width * win->height;
	win->img2 = tmp;
	win->pix_start2 = itmp;
	mlx_put_image_to_window(g_mlx_core, win->mlx_win, win->img2, 0, 0);
	return (0);
}
