/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:20:47 by mguinin           #+#    #+#             */
/*   Updated: 2013/11/25 15:54:25 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*res;

	if (lst && f)
	{
		res = f(lst);
		res = ft_lstnew(res->content, res->content_size);
		res->next = ft_lstmap(lst->next, f);
	}
	else
		res = NULL;
	return (res);
}
