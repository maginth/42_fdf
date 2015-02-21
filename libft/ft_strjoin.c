/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:53:12 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 17:08:57 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		l1;
	size_t		l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = (char *)malloc(l1 + l2 + 1);
	if (res)
	{
		ft_memcpy(res, (void *)s1, l1);
		ft_memcpy(res + l1, (void *)s2, l2 + 1);
	}
	return (res);
}
