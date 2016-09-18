/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_delete_no_children.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:30:02 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/17 23:30:03 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

void	ast_delete_no_children(t_ast *a)
{
	free(a->children);
	free(a->tag);
	free(a->value);
	free(a);
}
