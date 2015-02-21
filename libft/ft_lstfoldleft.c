/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfoldleft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:59:08 by mguinin           #+#    #+#             */
/*   Updated: 2013/11/25 16:10:55 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfoldleft(t_list *lst, void *a, void *(*f) (void *, void *))
{
	if (lst && f)
	{
		return (ft_lstfoldleft(lst->next, f(a, lst->content), f));
	}
	return (a);
}
