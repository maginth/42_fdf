/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:32:11 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/22 19:15:45 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnstrrec(const char *s1, const char *s2, size_t len,
							   size_t n)
{
	if (!*s1 || !n)
		return (NULL);
	if (ft_strncmp(s1, s2, len) == 0)
		return ((char *)s1);
	return (ft_strnstrrec(s1 + 1, s2, len, n - 1));
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;

	len = ft_strlen(s2);
	if (n < len)
		return (NULL);
	if (len == 0)
		return ((char *)s1);
	return (ft_strnstrrec(s1, s2, len, n - len + 1));
}
