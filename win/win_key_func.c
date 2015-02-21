/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_key_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 10:36:15 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/28 14:35:55 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "win.h"

void			win_key_func(t_win *win, t_uc key, t_fw f, void *p)
{
	g_key_bind[(int)key].win = win;
	g_key_bind[(int)key].func = f;
	g_key_bind[(int)key].param = p;
}