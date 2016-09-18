/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:30:15 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 02:58:29 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

t_ast	*ast_new(const char *key, const char *val)
{
	t_ast *ret;

	ret = ft_memalloc(sizeof(*ret));
	ret->tag = ft_strdup(key);
	ret->value = ft_strdup(val);
	return (ret);
}
