/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:22:33 by mguinin           #+#    #+#             */
/*   Updated: 2013/11/22 18:37:32 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*		ft_strcat(char *s1, const char *s2)
{
	return (ft_strncat(s1, s2, ft_strlen(s2)));
}