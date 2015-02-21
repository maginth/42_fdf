/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:49:37 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 21:34:45 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				refresh(void *param)
{
	t_refresh	*r;

	r = (t_refresh *)param;
	refresh_cam(r->cam, r->view);
	fill_win(r->win, 0);
	draw_grid(r->win, r->grid, r->style + r->view->affich_mod, r->cam);
	refresh_win(r->win);
	return (0);
}


t_c_alti		*read_color(int ac, char **av)
{
	t_c_alti	*color;
	int			i;

	color = (t_c_alti *)malloc(sizeof(t_c_alti) * (ac / 4 + 1));
	i = 0;
	while (ac > 0)
	{
		color[i].alti = ft_atoi(av[0]);
		color[i].c.i = (ft_atoi(av[1]) << 16)
					+ (ft_atoi(av[2]) << 8)
					+ ft_atoi(av[3]);
		av += 4;
		ac -= 4;
		i++;
	}
	color[i].alti = INT_MAX;
	color[i].c = color[i - 1].c;
	return (color);
}

void			init_style(t_style *style, t_c_alti	*color)
{
	if (!color)
	{
		color = (t_c_alti *)malloc(sizeof(t_c_alti) * 10);
		color[0] = (t_c_alti){(t_ucolor)0x000000, -10};
		color[1] = (t_c_alti){(t_ucolor)0x440088, -7};
		color[2] = (t_c_alti){(t_ucolor)0x0044bb, -2};
		color[3] = (t_c_alti){(t_ucolor)0x00ffee, 0};
		color[4] = (t_c_alti){(t_ucolor)0xffee88, 1};
		color[5] = (t_c_alti){(t_ucolor)0x33aa00, 2};
		color[6] = (t_c_alti){(t_ucolor)0x556600, 4};
		color[7] = (t_c_alti){(t_ucolor)0x773333, 8};
		color[8] = (t_c_alti){(t_ucolor)0xffffff, 11};
		color[9] = (t_c_alti){(t_ucolor)0xffffff, INT_MAX};
	}
	style[0] = (t_style){apply_perspect, NULL, NULL, put_raw_triangle, color};
	style[1] = (t_style){apply_perspect, NULL, put_raw_line, NULL, color};
	style[2] = (t_style){apply_proj, NULL, NULL, put_raw_triangle, color};
	style[3] = (t_style){apply_proj, NULL, put_raw_line, NULL, color};
}

void			init(int fd, char *name, t_c_alti *color)
{
	t_win		*win;
	t_cam		cam;
	t_view		view;
	t_style		style[AFFICH_MOD];
	t_grid		*grid;
	t_refresh	r;

	if ((grid = read_file(fd)) && (win = open_win(W_WIDTH, W_HEIGHT, name)))
	{
		view = (t_view){0.2, -1.0, 30, 0.001, -0.2, 500, 500, 1.3, 0};
		grid->view = &view;
		init_style(style, color);
		r = (t_refresh){win, grid, style, &cam, &view};
		refresh(&r);
		win_key_func(win, KEY_SPACE, change_mod, &r);
		loop_func(loop_key, &r);
		free(grid->coordinate);
		free(grid->trans);
		free(grid->pix);
		free(grid->shape);
		free(grid);
		free(color);
		close_win(win);
	}
}

int				main(int argc, char **argv)
{
	int			fd;
	t_c_alti	*color;
	int			mod;

	fd = 0;
	mod = argc % 4;
	if (mod > 2)
	{
		ft_putstr_fd("usage : fdf [<map>] [<alti> <red> <green> <blue>]\n", 2);
		return (EXIT_FAILURE);
	}
	if (mod == 2 && (fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("error opening file");
		return (EXIT_FAILURE);
	}
	if (mod == 1)
		ft_putstr("waiting map in stdin...\n");
	color = argc > 2 ? read_color(argc - mod, argv + mod) : NULL;
	init(fd, argv[1], color);
	return (EXIT_SUCCESS);
}
