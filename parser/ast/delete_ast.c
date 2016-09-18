/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_ast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:32:09 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/17 23:32:10 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	delete_ast(t_ast *a)
{
	int i;

	if (!a)
		return ;
	i = 0;
	while (i < a->n_children)
		delete_ast(a->children[i++]);
	free(a->children);
	free(a->tag);
	free(a->value);
	free(a);
}
