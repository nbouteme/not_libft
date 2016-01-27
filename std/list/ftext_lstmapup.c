/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:53:07 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 20:01:14 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFT_EXT
#include <libft/std.h>

static void wrapper(t_list *l, t_mapup_wrapper *tmw)
{
	ftext_lstpush_back(tmw->lst, tmw->f(l, tmw->up));
}

t_listhead	*ftext_lstmapup(t_listhead *lst, t_gen f, void *up);
{
	t_listhead		newlst;
	t_map_wrapper	tmw;

	newlst = ftext_lstnew();
	tmw = (t_map_wrapper){f, newlst, up};
	ftext_lstiterup(lst, wrapper, &tmw);
	return (newlst);
}
