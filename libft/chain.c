/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 17:35:07 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/22 19:14:08 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_chain		*chain_insert(t_chain *chain, void *data)
{
	t_chain		*res;

	res = (t_chain *)emalloc(sizeof(t_chain));
	if (chain)
	{
		res->next = chain;
		res->prev = chain->prev;
		if (res->next)
			res->next->prev = res;
		if (res->prev)
			res->prev->next = res;
	}
	else
		res->next = res->prev = res;
	res->data = data;
	return (res);
}

void	chain_remove(t_chain *chain)
{
	if (!chain)
		return ;
	if (chain->next)
		chain->next->prev = chain->prev;
	if (chain->prev)
		chain->prev->next = chain->next;
	free(chain);
}
