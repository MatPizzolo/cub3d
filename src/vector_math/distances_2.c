/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 03:44:48 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/16 19:14:41 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

t_vect	set_vect(float x, float y)
{
	t_vect	res;

	res.x = x;
	res.y = y;
	return (res);
}

t_vect	inter_lines_2(t_vect orig1, t_vect dir1, t_vect orig2, t_vect dir2)
{
	t_vect	segment;
	float	slope[2];

	slope[0] = dir1.y / dir1.x;
	slope[1] = dir2.y / dir2.x;
	if ((dir1.x == 0 && dir2.x == 0) || fabs(slope[0] - slope[1]) < 0.1)
		return (set_vect(INFINITY, INFINITY));
	if (dir1.x == 0)
	{
		segment.x = orig1.x;
		segment.y = slope[1] * (segment.x - orig2.x) + orig2.y;
	}
	else if (dir2.x == 0)
	{
		segment.x = orig2.x;
		segment.y = slope[0] * (segment.x - orig1.x) + orig1.y;
	}
	else if (slope [1] == 0)
	{
		segment.y = orig2.y;
		segment.x = (1 / slope[0]) * (segment.y - orig1.y) + orig1.x;
	}
	else
	{
		segment.y = ((-slope[0] / slope[1]) * orig2.y + slope[1] * orig2.x
				+ orig1.y - slope[0] * orig1.x) / (1 - slope[0] / slope[1]);
		segment.x = (segment.y - orig1.y) / slope[0] + orig1.x;
	}
	return (segment);
}


t_vect	inter_lines(t_vect orig1, t_vect dir1, t_vect orig2, t_vect dir2)
{
	float det[3];

	det[0] = dot_prod(dir1, dir1) * dot_prod(dir2, dir2) 
		- powf(dot_prod(dir1, dir2),2);
	if (det[0] == 0)
		return (set_vect(INFINITY, INFINITY));
	det[1] = (dot_prod(orig1, dir1) - dot_prod(orig2, dir1)) * (-1) 
		* (dot_prod(dir2, dir2)) - (- dot_prod(orig1, dir2) 
		+ dot_prod (orig2, dir2)) * dot_prod(dir1, dir2);
	det[2] = det[1] / det[0];
	return (add_v(orig1, f_x_v(det[2], dir1)));
}


float	vec_angle(t_vect base, t_vect other)
{
	float theta;
	float dotp;
	float det;

	dotp = dot_prod(base,other);
	theta = acosf(dotp/size_vect(base)/size_vect(other));
	det = base.x * other.y - base.y * other.x;
	if (det < 0)
		theta =  -theta;
	return(theta);
}


