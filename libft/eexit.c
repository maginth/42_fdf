/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 17:47:27 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/11 21:13:15 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void		*emalloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res)
		return (res);
	ft_putstr_fd("malloc failure\n", 2);
	exit(EXIT_FAILURE);
}

void		etest(int e, int err, char *msg)
{
	if (e == err)
	{
		ft_putstr_fd(msg, 2);
		exit(EXIT_FAILURE);
	}
}
