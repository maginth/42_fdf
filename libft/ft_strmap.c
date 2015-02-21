/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:30:46 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 16:59:30 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*i;
	int		j;

	if (s && f)
	{
		res = i = (char *)malloc(ft_strlen(s));
		j = 0;
		while (s[j])
			*(i++) = f(s[j++]);
		return (res);
	}
	return (NULL);
}
