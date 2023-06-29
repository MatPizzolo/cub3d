/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:10:27 by amejia            #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

float	dot_prod(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

// float dist_vec(t_vect v1[2], t_vect v2[2])
float	dist_vec(t_vect v1, t_vect v2)
{
	float	res;
	t_vect	temp;

	temp = sub_v(v2, v1);
	res = sqrtf(dot_prod(temp, temp));
	return (res);
}

float	size_vect(t_vect v)
{
	t_vect	zero;

	zero.x = 0;
	zero.y = 0;
	return (dist_vec(v, zero));
}

t_vect	norm_vect(t_vect v1)
{
	return (f_x_v(1 / size_vect(v1), v1));
}

t_vect	nearest_point(t_vect point, t_vect origin, t_vect director)
{
	t_vect	segment;
	float	proy;

	segment = sub_v(origin, point);
	director = norm_vect(director);
	proy = dot_prod(director, segment);
	segment = f_x_v(proy, director);
	segment = add_v(segment, point);
	return (segment);
}
