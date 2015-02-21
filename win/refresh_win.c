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
	mlx_put_image_to_window(g_mlx_core, win->mlx_win, win->img, 0, 0);
	return (0);
}