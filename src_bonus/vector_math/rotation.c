/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:37:05 by amejia            #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

// This function overwrites vec
t_vect	rotate_vector(t_vect vec, float rad)
{
	t_vect	temp;

	temp.x = cosf(rad) * vec.x - sinf(rad) * vec.y;
	temp.y = sinf(rad) * vec.x + cosf(rad) * vec.y;
	vec.x = temp.x;
	vec.y = temp.y;
	return (temp);
}

t_vect	neg_v(t_vect vec)
{
	vec.y = -vec.y;
	vec.x = -vec.x;
	return (vec);
}

t_vect	add_v(t_vect v1, t_vect v2)
{
	t_vect	res;

	res.y = v1.y + v2.y;
	res.x = v1.x + v2.x;
	return (res);
}

t_vect	sub_v(t_vect v1, t_vect v2)
{
	t_vect	res;

	res.y = v1.y - v2.y;
	res.x = v1.x - v2.x;
	return (res);
}

t_vect	f_x_v(float f, t_vect v)
{
	t_vect	res;

	res.x = v.x * f;
	res.y = v.y * f;
	return (res);
}
