/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:48:19 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 19:34:04 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			key_check_next(t_view *view)
{
	if (is_pressed(KEY_PGUP))
		view->alt_mult -= 0.02;
	else if (is_pressed(KEY_PGDW))
		view->alt_mult += 0.02;
	else if (is_pressed(KEY_COMA))
		view->perspec *= 1.1;
	else if (is_pressed(KEY_DOT) && view->perspec < 0.05)
		view->perspec /= 1.1;
	else if (is_pressed('z'))
		view->t_h -= 5;
	else if (is_pressed('q'))
		view->t_h += 5;
	else if (is_pressed('a'))
		view->t_v += 5;
	else if (is_pressed('d'))
		view->t_v -= 5;
	else if (is_pressed('w'))
		view->t_p -= 0.01;
	else if (is_pressed('s'))
		view->t_p += 0.01;
	else
		return (0);
	return (1);
}

static int			key_check(t_view *view)
{
	if (is_pressed(KEY_ESC))
		exit(0);
	else if (is_pressed(KEY_UP))
		view->r_h += 0.02;
	else if (is_pressed(KEY_DOWN))
		view->r_h -= 0.02;
	else if (is_pressed(KEY_RIGHT))
		view->r_z += 0.1;
	else if (is_pressed(KEY_LEFT))
		view->r_z -= 0.1;
	else if (is_pressed(KEY_PLUS) && view->zoom < 300)
		view->zoom *= 1.1;
	else if (is_pressed(KEY_MINUS))
		view->zoom *= 1 / 1.1;
	else
		return (key_check_next(view));
	return (1);
}

void				change_mod(t_win *win, void *param)
{
	t_refresh		*refsh;
	t_view			*view;

	win = win;
	refsh = (t_refresh *)param;
	view = refsh->view;
	view->affich_mod = (view->affich_mod + 1) % AFFICH_MOD;
	refresh(param);
}

int					loop_key(void *param)
{
	t_refresh		*refsh;

	refsh = (t_refresh *)param;
	if (key_check(refsh->view))
		refresh(param);
	return (0);
}
