/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:01:38 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 17:11:36 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t		len;
	char		*start;
	char		*res;

	if (!s)
		return (NULL);
	res = (char *)s;
	while (*res == ' ' || *res == '\t' || *res == '\n')
		res++;
	start = res;
	len = 0;
	while (*res && ++len)
		res++;
	res -= len != 0;
	while (*res == ' ' || *res == '\t' || *res == '\n')
	{
		res--;
		len--;
	}
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	res[len] = '\0';
	ft_memcpy(res, start, len);
	return (res);
}
