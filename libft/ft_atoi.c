/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:45:18 by mguinin           #+#    #+#             */
/*   Updated: 2013/11/23 14:35:55 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getsign(const char **s)
{
	int				sgn;

	sgn = 1;
	while (ft_memchr("\n\v\t\r\f ", **s, 6))
		(*s)++;
	sgn = **s == '-';
	if (sgn || **s == '+')
		(*s)++;
	return (sgn);
}

int		ft_atoi(const char *s)
{
	int		res;
	int		sgn;

	res = 0;
	sgn = ft_getsign(&s);
	while (ft_isdigit(*s))
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (sgn ? -res : res);
}
