/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:06:51 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:08:07 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/math.h>

t_vec3	vec3_cross(t_cvec3 a, t_cvec3 b)
{
	t_vec3 ret;

	ret = malloc(sizeof(*ret));
	(*ret)[0] = (*a)[1] * (*b)[2] - (*a)[2] * (*b)[1];
	(*ret)[1] = (*a)[2] * (*b)[0] - (*a)[0] * (*b)[2];
	(*ret)[2] = (*a)[0] * (*b)[1] - (*a)[1] * (*b)[0];
	return (ret);
}

t_vec3	vec3_add(t_cvec3 a, t_cvec3 b)
{
	t_vec3 ret;

	ret = malloc(sizeof(*ret));
	(*ret)[0] = (*a)[0] + (*b)[0];
	(*ret)[1] = (*a)[1] + (*b)[1];
	(*ret)[2] = (*a)[2] + (*b)[2];
	return (ret);
}

t_vec3	vec3_sub(t_cvec3 a, t_cvec3 b)
{
	t_vec3 ret;

	ret = malloc(sizeof(*ret));
	(*ret)[0] = (*a)[0] - (*b)[0];
	(*ret)[1] = (*a)[1] - (*b)[1];
	(*ret)[2] = (*a)[2] - (*b)[2];
	return (ret);
}

t_cvec3	vec3_up(void)
{
	const static float ret[3] = {0, 0, -1};

	return (&ret);
}

t_cvec3	vec3_zero(void)
{
	const static float ret[3] = {0, 0, 0};

	return (&ret);
}
