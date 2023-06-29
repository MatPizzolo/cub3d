/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 03:44:48 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

t_vect	set_vect(float x, float y)
{
	t_vect	res;

	res.x = x;
	res.y = y;
	return (res);
}

t_vect	inter_lines(t_vect orig1, t_vect dir1, t_vect orig2, t_vect dir2)
{
	float	det[3];

	det[0] = dot_prod(dir1, dir1) * dot_prod(dir2, dir2)
		- powf(dot_prod(dir1, dir2), 2);
	if (det[0] == 0)
		return (set_vect(INFINITY, INFINITY));
	det[1] = (dot_prod(orig1, dir1) - dot_prod(orig2, dir1)) * (-1)
		* (dot_prod(dir2, dir2)) - (-dot_prod(orig1, dir2)
			+ dot_prod (orig2, dir2)) * dot_prod(dir1, dir2);
	det[2] = det[1] / det[0];
	return (add_v(orig1, f_x_v(det[2], dir1)));
}

float	vec_angle(t_vect base, t_vect other)
{
	float	theta;
	float	dotp;
	float	det;

	dotp = dot_prod(base, other);
	if ((dotp / size_vect(base) / size_vect(other)) > 1)
		theta = 0;
	else if ((dotp / size_vect(base) / size_vect(other)) < -1)
		theta = PI;
	else
		theta = acosf(dotp / size_vect(base) / size_vect(other));
	det = base.x * other.y - base.y * other.x;
	if (det < 0)
		theta = -theta;
	return (theta);
}
