/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:43:32 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/22 19:20:01 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void*		ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	*bb;

	i = 0;
	bb = (unsigned char*)b;
	while (i < len)
	{
		bb[i] = c;
		i++;
	}
	return (b);
}

