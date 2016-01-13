/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:45:17 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/13 18:46:00 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include <stdlib.h>
# include <math.h>

# include "std.h"

typedef float	(*t_vec2)[2];
typedef float	(*t_vec3)[3];
typedef float	(*t_vec4)[4];
typedef float	(*t_mat3)[3][3];
typedef float	(*t_mat4)[4][4];

typedef const float	(*t_cvec3)[3];

t_mat3	new_mat3();
t_mat3	new_mat3_from_data(const float *data);
t_mat3	mat3_mult(t_mat3 a, t_mat3 b);
t_mat3	mat3_add(t_mat3 a, t_mat3 b);
t_vec3	vec3_copy(t_cvec3 rhs);
t_vec3	vec3_normalize(t_cvec3 rhs);
t_vec3	vec3_cross(t_cvec3 a, t_cvec3 b);
t_vec3	vec3_add(t_cvec3 a, t_cvec3 b);
t_vec3	vec3_sub(t_cvec3 a, t_cvec3 b);
t_vec4	vec4_from_a4(const float v[4]);
t_vec4	vec4_sdiv(t_vec4 a, float w);
t_vec4	vec4_smul(t_vec4 a, float n);
t_vec4	vec4_sadd(t_vec4 a, float n);
t_mat4	new_mat4();
t_mat4	new_mat4_from_data(const float *data);
t_mat4	mat4_mult(const t_mat4 a, const t_mat4 b);
t_mat4	mat4_add(t_mat4 a, t_mat4 b);
t_vec4	mat4_m_vec4(const t_mat4 a, const t_vec4 b);
t_mat4	translation(t_cvec3 pos);
t_mat4	mat4_lookat(t_cvec3 eye, t_cvec3 center, t_cvec3 up);
t_mat4	mat4_pers(float fov, float ar, float near, float far);
t_cvec3	vec3_up();
t_cvec3	vec3_zero();
float	vec3_norme(t_cvec3 rhs);
t_mat4	new_mat4_from_a4(const float x[4], const float y[4],
						const float z[4], const float w[4]);

#endif
