/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:07:55 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 16:46:21 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int nn)
{
	int			sgn;
	long		m;
	long		n;
	size_t		len;
	char		*res;

	sgn = nn < 0;
	n = sgn ? 0L - nn : nn;
	m = n;
	len = 0;
	while (m)
	{
		len++;
		m /= 10;
	}
	len += sgn || n == 0;
	res = ft_strnew(len);
	while (len--)
	{
		res[len] = '0' + (n % 10);
		n /= 10;
	}
	if (sgn)
		res[0] = '-';
	return (res);
}
