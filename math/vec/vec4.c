#include <libft/math.h>

t_vec4 vec4_from_a4(const float v[4])
{
	t_vec4 ret;

	ret = malloc(sizeof(*ret));
	ft_memcpy(ret, v, sizeof(float) * 4);
	return ret;
}

t_vec4 vec4_sdiv(t_vec4 a, float w)
{
	(*a)[0] /= w;
	(*a)[1] /= w;
	(*a)[2] /= w;
	(*a)[3] /= w;
	return a;
}

t_vec4 vec4_smul(t_vec4 a, float n)
{
	(*a)[0] *= n;
	(*a)[1] *= n;
	(*a)[2] *= n;
	(*a)[3] *= n;
	return a;
}

t_vec4 vec4_sadd(t_vec4 a, float n)
{
	(*a)[0] += n;
	(*a)[1] += n;
	(*a)[2] += n;
	(*a)[3] += n;
	return a;
}
