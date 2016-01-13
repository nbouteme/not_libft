/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:05:25 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:07:34 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/math.h>

t_vec3	vec3_copy(t_cvec3 rhs)
{
	t_vec3 ret;

	ret = malloc(sizeof(*rhs));
	ft_memcpy(ret, rhs, sizeof(*rhs));
	return (ret);
}

float	vec3_norme(t_cvec3 rhs)
{
	return (sqrt(((*rhs)[0] * (*rhs)[0]) +
				((*rhs)[1] * (*rhs)[1]) +
				((*rhs)[2] * (*rhs)[2])));
}

t_vec3	vec3_normalize(t_cvec3 rhs)
{
	float	norme;
	t_vec3	ret;

	ret = vec3_copy(rhs);
	norme = vec3_norme(rhs);
	(*ret)[0] /= norme;
	(*ret)[1] /= norme;
	(*ret)[2] /= norme;
	return (ret);
}
