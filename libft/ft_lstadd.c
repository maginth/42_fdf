/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:18:53 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/04 16:46:58 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = NULL;
}
