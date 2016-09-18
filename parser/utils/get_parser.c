/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:31:44 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:58:45 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

static int	stmt_name_f(t_dlist *a, void *n)
{
	t_statement *d;

	d = a->content;
	return (ft_strcmp(d->name, n) == 0);
}

t_parser	*get_parser(t_symtable *sy, char *sn)
{
	t_parser	*p;
	t_dlist		*e;

	e = ftext_lstfind(sy->syms, stmt_name_f, sn);
	if (e)
		return ((t_statement*)e->content)->gr;
	p = init_parser(malloc(sizeof(*p) + 0x30), 0, do_nothing);
	p->size += 0x30;
	p->name = ft_strdup(sn);
	e = ftext_lstnewelem(&(t_statement){ft_strdup(sn), p}, sizeof(t_statement));
	ftext_lstpush_back(sy->syms, e);
	return (p);
}
