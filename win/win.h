/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 10:38:23 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/28 14:41:48 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** compilation flags : -L/usr/X11/lib -lXext -lX11 -lmlx
*/

#ifndef WIN_H
# define WIN_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <limits.h>
# define KEY_ESC 27
# define KEY_UP 'R'
# define KEY_DOWN 'T'
# define KEY_RIGHT 'S'
# define KEY_LEFT 'Q'
# define KEY_PLUS 171
# define KEY_MINUS 173
# define KEY_PGUP 'U'
# define KEY_PGDW 'V'
# define KEY_SPACE 32
# define KEY_ZERO 48
# define KEY_DOT '.'
# define KEY_COMA ','

/*
** mlx_win amd img are private fields;
*/

typedef	unsigned char	t_uc;

typedef	struct			s_win
{
    void				*mlx_win;
	int					*pix_start;
	void				*img;
	int					*pix_end;
	int					width;
	int					height;
	int					*pix_start2;
	void				*img2;
}						t_win;

typedef	void (*t_fw)(t_win *, void *param);

typedef struct			s_key_bind
{
	int					pressed;
	t_win				*win;
	t_fw				func;
	void				*param;
}						t_key_bind;

int						g_win_count;
void					*g_mlx_core;
t_key_bind				g_key_bind[256];


t_win					*open_win(int width, int height, char *name);
void					close_win(t_win *win);
void					fill_win(t_win *win, int color);
int						refresh_win(t_win *win);
void					win_key_func(t_win *win, t_uc key, t_fw fw, void *p);
void					loop_func(int (*func)(void *), void *param);
int						is_pressed(t_uc key);
/*
** private
*/
void					init_mlx(void);

#endif
