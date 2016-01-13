/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:57:42 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:00:25 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/math.h>

t_mat4	new_mat4(void)
{
	t_mat4 ret;

	ret = malloc(sizeof(*ret));
	ft_bzero(ret, sizeof(*ret));
	return (ret);
}

t_mat4	new_mat4_from_a4(const float x[4], const float y[4],
						const float z[4], const float w[4])
{
	t_mat4 ret;

	ret = malloc(sizeof(*ret));
	ft_memcpy((*ret)[0], x, sizeof(float) * 4);
	ft_memcpy((*ret)[1], y, sizeof(float) * 4);
	ft_memcpy((*ret)[2], z, sizeof(float) * 4);
	ft_memcpy((*ret)[3], w, sizeof(float) * 4);
	return (ret);
}

t_mat4	new_mat4_from_data(const float *data)
{
	t_mat4 ret;

	ret = malloc(sizeof(*ret));
	ft_memcpy(ret, data, sizeof(ret));
	return (ret);
}

t_mat4	mat4_mult(const t_mat4 a, const t_mat4 b)
{
	t_mat4	c;
	int		i;
	int		j;
	int		k;

	c = new_mat4();
	i = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			j = 0;
			while (j < 4)
			{
				(*c)[i][j] += (*a)[i][k] * (*b)[k][j];
				++j;
			}
			++k;
		}
		++i;
	}
	return (c);
}

t_mat4	mat4_add(t_mat4 a, const t_mat4 b)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*a)[i][j] += (*b)[i][j];
			++j;
		}
		++i;
	}
	return (a);
}
