/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:33:10 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 16:36:59 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void*		ft_memccpy(void *s1, const void *s2, int c, int len)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (i < len)
	{
		if ((c1[i] = c2[i]) == c)
		{
			return (c1 + i + 1);
		}
		i++;
	}
	return (NULL);
}
