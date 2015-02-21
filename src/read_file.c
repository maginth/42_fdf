/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 17:10:21 by mguinin           #+#    #+#             */
/*   Updated: 2015/01/31 19:49:38 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		skip_space(int fd)
{
	char	c;

	while (read(fd, &c, 1) == 1)
	{
		if (c != ' ')
			return (c);
	}
	return ('\0');
}

char		read_num(int fd, char c, short *num)
{
	char	buf[7];
	int		i;

	i = 0;
	while (c != ' ' && c != '\n' && i < 6)
	{
		if (!ft_isdigit(c) && !(c == '-' && i == 0))
		{
			ft_putstr_fd("wrong character in file", 2);
			exit(-1);
		}
		buf[i++] = c;
		if (read(fd, &c, 1) != 1)
			break ;
	}
	if (i == 6)
	{
		ft_putstr_fd("number to big", 2);
		exit(-1);
	}
	buf[i] = '\0';
	*num = ft_atoi(buf);
	return (c);
}

t_grid		*read_file(int fd)
{
	short	buf[MAX_POINT + 2];
	char	c;
	int		i;

	i = 0;
	while ((c = skip_space(fd)) && i < MAX_POINT)
	{
		if (c == '\n')
			buf[i++] = NEW_LINE;
		else
		{
			c = read_num(fd, c, buf + i++);
			if (c == '\n')
				buf[i++] = NEW_LINE;
		}
	}
	buf[i] = NEW_LINE;
	close(fd);
	return (make_grid(buf, i));
}
