/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:30:46 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 17:09:48 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*i;
	unsigned int	j;

	if (s && f)
	{
		j = 0;
		if (!(res = i = (char *)malloc(ft_strlen(s))))
			return (NULL);
		while (s[j])
		{
			*(i++) = f(j, s[j]);
			j++;
		}
		return (res);
	}
	return (NULL);
}
