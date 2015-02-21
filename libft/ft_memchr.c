/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:57:03 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 17:03:03 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void*		ft_memchr(const void *s1, int c, size_t n)
{
	unsigned char		*s;

	if (!s1 || !n)
		return (NULL);
	s = (unsigned char*)s1;
	while (n--)
	{
		if (*s == (unsigned char)c)
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}
