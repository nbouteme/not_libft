/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftext_lstmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:53:07 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 19:59:09 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFT_EXT
#include <libft/std.h>

static void wrapper(t_list *l, t_map_wrapper *tmw)
{
	ftext_lstpush_back(tmw->lst, tmw->f(l));
}

t_listhead	*ftext_lstmap(t_listhead *lst, t_gen f);
{
	t_listhead		newlst;
	t_map_wrapper	tmw;

	newlst = ftext_lstnew();
	tmw = (t_map_wrapper){f, newlst};
	ftext_lstiterup(lst, wrapper, &tmw);
	return (newlst);
}
