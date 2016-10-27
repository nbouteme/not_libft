/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:37:48 by nbouteme          #+#    #+#             */
/*   Updated: 2016/10/28 00:02:28 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <libft/parser.h>

static char	*build_error(const char *e, t_fpos *pos)
{
	char *tmp;
	char *n1;
	char *n2;

	n1 = ft_itoa(pos->line);
	n2 = ft_itoa(pos->col);
	tmp = ft_memalloc(ft_strlen("Expected `` at :\n") + ft_strlen(n1)
					+ ft_strlen(n2) + ft_strlen(e) + 1);
	ft_strcat(tmp, "Expected `");
	ft_strcat(tmp, e);
	ft_strcat(tmp, "` at ");
	ft_strcat(tmp, n1);
	ft_strcat(tmp, ":");
	ft_strcat(tmp, n2);
	ft_strcat(tmp, "\n");
	free(n1);
	free(n2);
	return (tmp);
}

t_error		*new_error(t_input *i, const char *e)
{
	char	*str;
	t_fpos	*pos;
	t_error	*ret;

	if (i->suppress)
		return (0);
	pos = get_istate(i);
	str = build_error(e, pos);
	ret = ft_memalloc(sizeof(*ret) + ft_strlen(str) + 1);
	ret->loc = *pos;
	free(pos);
	ft_strcpy(ret->expected, str);
	free(str);
	return (ret);
}

int			exp_match(t_parser *base, t_input *i, void **out)
{
	t_exp_p	*self;
	void	*tmp;

	self = (void*)base;
	tmp = i->cursor;
	*out = 0;
	i->suppress++;
	if (self->p->match_fun(self->p, i, out))
	{
		i->suppress--;
		return (1);
	}
	free(*out);
	i->suppress--;
	*out = new_error(i, self->e);
	i->cursor = tmp;
	return (0);
}

void		delete_exp(t_parser *p)
{
	t_exp_p *s;

	s = (void*)p;
	delete_parser(s->p);
	free(s->e);
}

t_parser	*exp_p(t_parser *p, const char *e)
{
	t_exp_p *ret;

	ret = init_parser(malloc(sizeof(*ret)), exp_match, delete_exp);
	ret->base.size = sizeof(*ret);
	ret->e = ft_strdup(e);
	ret->p = p;
	return (&ret->base);
}
