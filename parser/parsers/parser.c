/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:23:54 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:48:01 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	*init_parser(t_parser *p, t_match_f m, t_pdtor d)
{
	ft_memset(p, 0, sizeof(*p));
	p->dtor = d;
	p->match_fun = m;
	p->freeing = 0xDEADC0DE;
	p->size = sizeof(*p);
	return (p);
}

void	delete_parser(void *base)
{
	t_parser *self;

	self = base;
	if (!self || self->freeing != 0xDEADC0DE)
		return ;
	if (!*get_plist())
		*get_plist() = ftext_lstnew();
	if (ftext_lstfind(*get_plist(), find_ptr, base))
		return ;
	ftext_lstpush_back(*get_plist(), ftext_lstnewelemown(base, 0));
	free(self->name);
	self->dtor(base);
}

void	actual_delete(t_parser *self)
{
	if (!self || self->freeing != 0xDEADC0DE)
		return ;
	self->freeing = 0;
	free(self);
}

void	delete_parsers(void)
{
	ftext_lstdel(get_plist(), (void*)actual_delete);
}

void	assign_parser(t_parser *a, t_parser *b)
{
	char *n;

	n = a->name;
	ft_memcpy(a, b, b->size);
	a->name = n;
	free(b);
}
