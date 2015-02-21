/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:17:22 by mguinin           #+#    #+#             */
/*   Updated: 2013/11/22 18:54:20 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	if ((char)c == '\0')
	{
		return (ft_strchr(s, c));
	}
	s = tmp = ft_strchr(s, c);
	while (tmp)
	{
		s = tmp;
		tmp = ft_strchr(tmp + 1, c);
	}
	return ((char *)s);
}
