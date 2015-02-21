/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:45:38 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 16:44:00 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*		ft_memmove(void *s1, const void *s2, size_t len)
{
	int				dif;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	if (c2 < c1 && c2 + len > c1)
	{
		dif = c1 - c2;
		ft_memmove(c1 + dif, c1, len - dif);
		ft_memcpy(c1, c2, dif);
		return (s1);
	}
	ft_memcpy(c1, c2, len);
	return (s1);
}
