/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:56:42 by nbouteme          #+#    #+#             */
/*   Updated: 2015/11/23 18:18:13 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void    ft_striter(char *s, void (*f)(char *))
{
	size_t len;
	size_t i;

	len = ft_strlen(s);
	i = 0;
	while(i < len)
		f(&s[i]);}

char   *ft_strmap(char const *s, char (*f)(char))
{
	size_t len;
	size_t i;
	char *m;

	len = ft_strlen(s);
	m = malloc(len * sizeof(char));
	i = 0;
	while(i < len)
		m[i] = f(s[i]);
	return m;
}

void    ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t len;
	size_t i;

	len = ft_strlen(s);
	i = 0;
	while(i < len)
		f(i, &s[i]);
}

char   *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t len;
	size_t i;
	char *m;

	len = ft_strlen(s);
	m = malloc(len * sizeof(char));
	i = 0;
	while(i < len)
		m[i] = f(i, s[i]);
	return m;
}
