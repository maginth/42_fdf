/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:20:05 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 17:01:07 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char		*ft_strndup(char *s, size_t n)
{
	char		*res;

	res = (char *)malloc(n + 1);
	if (res)
	{
		ft_memcpy(res, s, n);
		res[n] = '\0';
	}
	return (res);
}

char		**ft_strsplit_rec(int index, char *s, char c)
{
	char		**res;
	size_t		len;

	while (*s == c)
		s++;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	res = len ? ft_strsplit_rec(index + 1, s + len, c) :
		(char **)malloc(sizeof(*res) * (index + 1));
	if (res)
		res[index] = len ? ft_strndup(s, len) : NULL;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	return (s ? ft_strsplit_rec(0, (char *)s, c) : NULL);
}
