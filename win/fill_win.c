/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 10:36:15 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/27 12:31:24 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "win.h"

void			fill_win(t_win *win, int color)
{
	int			*start;
	int			*i;

	start = win->pix_start;
	i = win->pix_end;
	while (--i != start)
		*i = color;
}