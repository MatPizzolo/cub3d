/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:20:37 by amejia            #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

//it[0] first value to check, it[1] direction
void	ray_x_intersect(t_global *vars, t_vect *posib)
{
	int	it[2];

	it[0] = (int)floorf(vars->char_pos.x);
	it[1] = -1;
	if (posib[2].x == 0)
		posib[0] = set_vect(-1, -1);
	else
	{
		if (posib[2].x > 0)
		{
			it[1] = 1;
			it[0]++;
		}
		while (it[0] > 0 && it[0] < vars->map_columns)
		{
			posib[0] = inter_lines(vars->char_pos, posib[2], set_vect(it[0], 0),
					set_vect(0, 1));
			if (check_x_quality(vars, posib, it))
				break ;
			it[0] += it[1];
		}
		if (it[0] == vars->map_columns || it[0] == 0)
			posib[0] = set_vect(-1, -1);
	}
}

// it[0] es it it[1] es dir
void	ray_y_intersect(t_global *vars, t_vect *posib)
{
	int	it[2];

	it[0] = (int)floorf(vars->char_pos.y);
	it[1] = -1;
	if (posib[2].y == 0)
		posib[1] = set_vect(-1, -1);
	else
	{
		if (posib[2].y > 0)
		{
			it[1] = 1;
			it[0]++;
		}
		while (it[0] > 0 && it[0] < vars->map_rows)
		{
			posib[1] = inter_lines(vars->char_pos, posib[2],
					set_vect(0, it[0]), set_vect(1, 0));
			if (check_y_quality(vars, posib, it))
				break ;
			it[0] += it[1];
		}
		if (it[0] == vars->map_rows || it[0] == 0)
			posib[1] = set_vect(-1, -1);
	}
}

t_vect	choose_best_intersect(t_global *vars, t_vect *posib, int *x_y)
{
	*x_y = 1;
	if (dist_vec(posib[0], set_vect(-1, -1)) == 0 && \
		dist_vec(posib[1], set_vect(-1, -1)) == 0)
	{
		*x_y = -1;
		return (set_vect(-1, -1));
	}
	else if (dist_vec(posib[0], set_vect(-1, -1)) == 0 && \
		dist_vec(posib[1], set_vect(-1, -1)) > 0)
		return (posib[1]);
	else if (dist_vec(posib[0], set_vect(-1, -1)) > 0 && \
		dist_vec(posib[1], set_vect(-1, -1)) == 0)
	{
		*x_y = 0;
		return (posib[0]);
	}
	else if (dist_vec(posib[0], vars->char_pos) > dist_vec(posib[1],
			vars->char_pos))
		return (posib[1]);
	*x_y = 0;
	return (posib[0]);
}

t_vect	calc_ray_intersect(t_global *vars, int hor_pix, int *x_y)
{
	t_vect	posib[3];
	float	pix_rot;

	if (hor_pix < 960)
		pix_rot = -atan((960 - hor_pix) / D_TO_SCREEN);
	else
		pix_rot = atan((hor_pix - 960) / D_TO_SCREEN);
	posib[2] = rotate_vector(vars->char_facing, pix_rot);
	ray_x_intersect(vars, posib);
	ray_y_intersect(vars, posib);
	return (choose_best_intersect(vars, posib, x_y));
}

t_image	*texture_selector(t_global *vars, t_vect intersect, int x_y)
{
	if (!(x_y == 0 || x_y == 1))
		return (NULL);
	if (x_y == 0 && sub_v(intersect, vars->char_pos).x < 0)
		return (vars->we_texture);
	if (x_y == 0 && sub_v(intersect, vars->char_pos).x >= 0)
		return (vars->ea_texture);
	if (x_y == 1 && sub_v(intersect, vars->char_pos).y < 0)
		return (vars->no_texture);
	if (x_y == 1 && sub_v(intersect, vars->char_pos).y >= 0)
		return (vars->so_texture);
	return (NULL);
}
