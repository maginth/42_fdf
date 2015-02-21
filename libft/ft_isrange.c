/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:11:03 by mguinin           #+#    #+#             */
/*   Updated: 2013/11/23 13:53:34 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isrange(int c, int a, int b)
{
	return ((a <= c) && (c <= b));
}
