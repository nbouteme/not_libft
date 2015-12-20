#include <libft/math.h>

t_mat4 new_mat4()
{
	t_mat4 ret;

	ret = malloc(sizeof(*ret));
	ft_bzero(ret, sizeof(*ret));
	return ret;
}

t_mat4 new_mat4_from_a4(const float x[4], const float y[4],
						const float z[4], const float w[4])
{
	t_mat4 ret;

	ret = malloc(sizeof(*ret));
	ft_memcpy((*ret)[0], x, sizeof(float) * 4);
	ft_memcpy((*ret)[1], y, sizeof(float) * 4);
	ft_memcpy((*ret)[2], z, sizeof(float) * 4);
	ft_memcpy((*ret)[3], w, sizeof(float) * 4);
	return ret;	
}

t_mat4 new_mat4_from_data(const float *data)
{
	t_mat4 ret;

	ret = malloc(sizeof(*ret));
	ft_memcpy(ret, data, sizeof(ret));
	return ret;
}

t_mat4 mat4_mult(const t_mat4 a, const t_mat4 b)
{
	t_mat4 c;
	int i;
	int j;
	int k;

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
	return c;
}

t_mat4 mat4_add(t_mat4 a, const t_mat4 b)
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
	return a;
}

/* t_vec4 mat4_m_vec4(const t_mat4 a, const t_vec4 b) */
/* { */
/* 	int i; */
/* 	t_vec4 ret; */

/* 	ret = ft_memalloc(sizeof(*ret)); */
/* 	i = -1; */
/* 	while(++i < 4) */
/* 	{ */
/* 		(*ret)[i] += (*a)[i][0] * (*b)[0]; */
/* 		(*ret)[i] += (*a)[i][1] * (*b)[1]; */
/* 		(*ret)[i] += (*a)[i][2] * (*b)[2]; */
/* 		(*ret)[i] += (*a)[i][3] * (*b)[3]; */
/* 	} */
/* 	return ret; */
/* } */

t_vec4 mat4_m_vec4(const t_mat4 a, const t_vec4 b)
{
	return (vec4_from_a4((float[]){ (*a)[0][0] * (*b)[0] + (*a)[1][0] * (*b)[1]
					+ (*a)[2][0] * (*b)[2] + (*a)[3][0] * (*b)[3], (*a)[0][1]
					* (*b)[0] + (*a)[1][1] * (*b)[1] + (*a)[2][1] * (*b)[2]
					+ (*a)[3][1] * (*b)[3], (*a)[0][2] * (*b)[0] + (*a)[1][2] *
					(*b)[1] + (*a)[2][2] * (*b)[2] + (*a)[3][2] * (*b)[3],
					(*a)[0][3] * (*b)[0] + (*a)[1][3] * (*b)[1] + (*a)[2][3] * (*b)[2]
					+ (*a)[3][3] * (*b)[3]}));
}
