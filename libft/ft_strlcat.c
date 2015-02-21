/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:02:02 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 17:03:47 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		len2;

	len = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size <= len)
	{
		return (size + len2);
	}
	else
	{
		ft_strncat(dst, src, size - len - 1);
		return (len + len2);
	}
}
