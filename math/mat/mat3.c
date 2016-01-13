/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:00:45 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:01:44 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/math.h>

t_mat3	new_mat3(void)
{
	t_mat3 ret;

	ft_bzero(&ret, sizeof(ret));
	return (ret);
}

t_mat3	new_mat3_from_data(const float *data)
{
	t_mat3 ret;

	ft_memcpy(&ret, data, sizeof(ret));
	return (ret);
}

t_mat3	mat3_mult(t_mat3 a, t_mat3 b)
{
	t_mat3	c;
	int		i;
	int		j;
	int		k;

	c = new_mat3();
	i = 0;
	while (i < 3)
	{
		k = 0;
		while (k < 3)
		{
			j = 0;
			while (j < 3)
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

t_mat3	mat3_add(t_mat3 a, t_mat3 b)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			(*a)[i][j] += (*b)[i][j];
			++j;
		}
		++i;
	}
	return (a);
}
