/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:02:05 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 19:05:05 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/math.h>

t_mat4	translation(t_cvec3 pos)
{
	t_mat4 reto;

	reto = new_mat4_from_a4((float[4]){ 1, 0, 0, -(*pos)[0] },
							(float[4]){ 0, 1, 0, -(*pos)[1] },
							(float[4]){ 0, 0, 1, -(*pos)[2] },
							(float[4]){ 0, 0, 0, 1 });
	return (reto);
}

float	vec3_dot(t_cvec3 a, t_cvec3 b)
{
	return ((*a)[0] * (*b)[0] +
			(*a)[1] * (*b)[1] +
			(*a)[2] * (*b)[2]);
}

t_mat4	mat4_lookat(t_cvec3 eye, t_cvec3 center, t_cvec3 up)
{
	t_mat4 look;
	t_vec3 f;
	t_vec3 s;
	t_vec3 u;
	t_vec3 temp;

	temp = vec3_sub(center, eye);
	f = vec3_normalize(temp);
	free(temp);
	temp = vec3_cross(f, up);
	s = vec3_normalize(temp);
	free(temp);
	u = vec3_cross(s, f);
	look = new_mat4_from_a4((float[4]){(*s)[0], (*u)[0], -(*f)[0], 0},
							(float[4]){(*s)[1], (*u)[1], -(*f)[1], 0},
							(float[4]){(*s)[2], (*u)[2], -(*f)[2], 0},
							(float[4]){-vec3_dot(s, eye), -vec3_dot(u, eye),
									vec3_dot(f, eye), 1});
	free(u);
	free(s);
	free(f);
	return (look);
}

t_mat4	mat4_pers(float fov, float ar, float near, float far)
{
	t_mat4	mper;
	float	dist;
	float	tanf2;

	dist = far - near;
	tanf2 = tan(fov / 2);
	mper = new_mat4_from_a4((float[4]){ 1.0f / (ar * tanf2), 0, 0, 0 },
							(float[4]){ 0, 1.0f / tanf2, 0, 0 },
							(float[4]){ 0, 0, -(near + far) / dist, -1 },
							(float[4]){ 0, 0, -(2 * near * far) / dist, 0 });
	return (mper);
}
