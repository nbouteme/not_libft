/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:53:07 by nbouteme          #+#    #+#             */
/*   Updated: 2016/02/05 02:54:17 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/std.h>
#include "lst_wrappers.h"

static void	wrapper(t_dlist *l, t_map_wrapper *tmw)
{
	ftext_lstpush_back(tmw->h, tmw->f(l));
}

t_dlisthead	*ftext_lstmap(t_dlisthead *lst, t_dgen f)
{
	t_dlisthead		*newlst;
	t_map_wrapper	tmw;

	newlst = ftext_lstnew();
	tmw = (t_map_wrapper){f, newlst};
	ftext_lstiterup(lst, (void*)wrapper, &tmw);
	return (newlst);
}
