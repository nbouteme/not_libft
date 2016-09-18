/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:28:28 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:28:53 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

t_parser	*tokbra_parser(t_parser *p)
{
	return (tok_between_parser(p, "<", ">"));
}

t_parser	*tok_parser(t_parser *p)
{
	return (and_parser(free, eval_second, 3,
					(t_parser*[]){blank_parser(), p, blank_parser()}));
}
