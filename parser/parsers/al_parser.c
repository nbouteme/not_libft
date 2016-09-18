/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:59:15 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:01:46 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

#define ALNUM "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHA "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

static t_parser	*i_alnum_parser(void)
{
	return (oneof_parser(ALNUM));
}

static t_parser	*i_alpha_parser(void)
{
	return (oneof_parser(ALPHA));
}

t_parser		*alpha_parser(void)
{
	return (exp_p(i_alpha_parser(), "alpha char"));
}

t_parser		*alnum_parser(void)
{
	return (exp_p(i_alnum_parser(), "alpha char"));
}
