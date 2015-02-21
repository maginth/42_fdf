/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 10:36:15 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/28 14:45:23 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "win.h"

int				g_win_count = 0;

int				key_press(int key)
{
	g_key_bind[key & 0xff].pressed = 1;
	return (0);
}

int				key_release(int key, void *param)
{
	t_win		*win;
	t_key_bind	*k;

	win = (t_win *)param;
	k = g_key_bind + (key & 0xff);
	k->pressed = 0;
	if (k->func && (k->win == win || k->win == NULL))
		k->func(win, k->param);
	return (0);
}

t_win			*open_win(int width, int height, char *name)
{
	t_win		*win;
	int			bpp;
	int			size_l;
	int			endian;

	init_mlx();
	win = (t_win *)malloc(sizeof(t_win));
	win->mlx_win = mlx_new_window(g_mlx_core, width, height, name);
	win->img = mlx_new_image(g_mlx_core, width, height);
	win->pix_start =
		(int *)mlx_get_data_addr(win->img, &bpp, &size_l, &endian);
	if (bpp != 32)
		exit(EXIT_FAILURE);
	win->width = width;
	win->height = height;
	win->pix_end = win->pix_start + width * height;
	mlx_expose_hook(win, refresh_win, (void *)win);
	mlx_hook(win->mlx_win, 2, 1, key_press, 0);
	mlx_key_hook(win->mlx_win, key_release, win);
	g_win_count++;
	return (win);
}