/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 18:51:04 by mguinin           #+#    #+#             */
/*   Updated: 2015/02/21 18:31:10 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_midx(short *buf)
{
	int		i;

	i = 0;
	while (buf[i] != NEW_LINE)
		i++;
	return (1 + (i / 2));
}


void		link_seg_line(t_grid *g, int i, int line_end)
{
	int		n;

	n = g->size;
	while (i < line_end)
	{
		g->shape[n++] = (t_shape){i, i + 1, -1};
		i++;
	}
	g->size = n;
}

void		link_shapes(t_grid *g, int i, int i_prev, int end)
{
	int		n;
	int		i_prev_end;

	i_prev_end = i - 1;
	n = g->size;
	while (i < end && i_prev < i_prev_end)
	{
		if (g->coordinate[i].z + g->coordinate[i_prev + 1].z 
			> g->coordinate[i + 1].z + g->coordinate[i_prev].z)
		{
			g->shape[n++] = (t_shape){i_prev + 1, i + 1, i};
			g->shape[n++] = (t_shape){i_prev, i_prev + 1, i};
		}
		else
		{
			g->shape[n++] = (t_shape){i_prev, i + 1, i};
			g->shape[n++] = (t_shape){i_prev, i_prev + 1, i + 1};
		}
		g->shape[n++] = (t_shape){i, i_prev, -1};
		i++;
		i_prev++;
	}
	if (i_prev == end || i_prev == i_prev_end)
		g->shape[n++] = (t_shape){i, i_prev, -1};
	g->size = n;
}

void		fill_grid(t_grid *g, short *buf, int midx, int size)
{
	int		x;
	int		y;
	int		n;
	int		start_line;
	int		prev_line;

	y = -size / (4 * midx);
	prev_line = -1;
	n = 0;
	while (size > 0)
	{
		x = -midx;
		start_line = n;
		while (*buf++ != NEW_LINE)
			g->coordinate[n++] = (t_point){x++, y, buf[-1]};
		size -= n - start_line + 1;
	    y++;
    	link_seg_line(g, start_line, n - 1);
    	if (start_line)
    		link_shapes(g, start_line, prev_line, n - 1);
	    prev_line = start_line;
	}
}

t_grid		*make_grid(short *buf, int size)
{
	t_grid	*grid;

	grid = (t_grid *)malloc(sizeof(*grid));
	grid->coordinate = (t_point *)malloc(sizeof(t_point) * size);
	grid->trans = (t_point *)malloc(sizeof(t_point) * size);
	grid->pix = (t_pix *)malloc(sizeof(t_pix) * size);
	grid->shape = (t_shape *)malloc(sizeof(t_shape) * size * 4);
	grid->size = 0;
	fill_grid(grid, buf, get_midx(buf), size);
	grid->shape_nb = grid->size;
	grid->size = size;
	return (grid);
}
