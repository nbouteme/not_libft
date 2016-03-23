/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstfilter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:37:31 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:57:39 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_wrappers.h"
#include <stdlib.h>

static t_dlist	*shallow_copy(const t_dlist *elem)
{
	return (ft_memcpy(malloc(sizeof(*elem)),
					elem,
					sizeof(*elem)));
}

static void		*wrapper(t_dlist *elem, t_reduceup_wrapper *args)
{
	if (args->f(elem, args->u))
		ftext_lstpush_back(args->h, args->c(elem));
	return (args);
}

t_dlisthead		*ftext_lstfilterup(t_dlisthead *lst, t_dkeepup f, t_dcopy c,
							void *u)
{
	t_reduceup_wrapper args;

	c = c ? c : shallow_copy;
	args = (t_reduceup_wrapper){ f, ftext_lstnew(), c, u };
	ftext_lstiterup(lst, (void*)wrapper, &args);
	return (args.h);
}
