/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:28:22 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 16:36:18 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	unsigned char		*mem;
	unsigned char		*i;

	mem = (unsigned char *)malloc(size);
	if (mem)
	{
		i = mem + size;
		while (i != mem)
		{
			i--;
			*i = 0;
		}
	}
	return (mem);
}
