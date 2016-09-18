/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astfold.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 01:15:04 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 01:16:24 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	*astfold(int n, void **o)
{
	int		i[2];
	t_ast	**as;
	t_ast	*r;

	as = (t_ast**)o;
	if (n <= 1)
		return (n ? o[0] : 0);
	if (n == 2 && (!o[0] || !o[1]))
		return (o[0] ? o[0] : o[1]);
	r = ast_new(">", "");
	*i = -1;
	while (++i[0] < n)
		if (as[*i])
		{
			if (as[*i]->n_children <= 1)
				ast_add_child(r, as[*i]->n_children ?
				ast_add_root_tag(as[*i]->children[0], as[*i]->tag) : as[*i]);
			else if ((i[1] = -1))
				while (++i[1] < as[*i]->n_children)
					ast_add_child(r, as[*i]->children[i[1]]);
			if (as[*i]->n_children)
				ast_delete_no_children(as[*i]);
		}
	r->loc = r->n_children ? r->children[0]->loc : r->loc;
	return (r);
}
