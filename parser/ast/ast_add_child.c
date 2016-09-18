/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_add_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:28:02 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:43:14 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

t_ast	*ast_add_child(t_ast *r, t_ast *c)
{
	void *tmp;

	tmp = r->children;
	r->children = malloc(sizeof(void*) * (r->n_children + 1));
	ft_memcpy(r->children, tmp, sizeof(void*) * r->n_children);
	r->children[r->n_children++] = c;
	free(tmp);
	return (r);
}
