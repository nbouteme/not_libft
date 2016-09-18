/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blk_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:05:28 by nbouteme          #+#    #+#             */
/*   Updated: 2016/09/18 00:05:29 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/parser.h>

t_parser	*wht_parser(void)
{
	return (oneof_parser(" \n\t\r\v\f"));
}

t_parser	*whts_parser(void)
{
	return (zom_parser(strfold, wht_parser()));
}

t_parser	*blank_parser(void)
{
	return (whts_parser());
}
