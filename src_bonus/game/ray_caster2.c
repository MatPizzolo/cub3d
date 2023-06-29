/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:25:49 by amejia            #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	render_wall_col_setup(t_global *vars, int *ct, t_image *img,
	t_vect intersect)
{
	t_wall_rend	p;

	p.column = ct[2];
	p.img_dst = img;
	p.position[0] = ct[3];
	p.position[1] = ct[4];
	p.size = W_SIZE / (dist_vec(vars->char_pos, intersect) + 0.1);
	p.n_wall = texture_selector(vars, intersect, ct[1]);
	render_wall_col(&p);
}

int	check_x_quality(t_global *vars, t_vect *posib, int *it)
{
	if (posib[0].y > 0 && posib[0].y < vars->map_rows
		&& (int)floorf(posib[0].y) >= 0
		&& (int)floorf(posib[0].y) < vars->map_rows
		&& it[0] + (it[1] - 1) / 2 >= 0
		&& it[0] + (it[1] - 1) / 2 < vars->map_columns
		&& vars->map[
			(int)floorf(posib[0].y)][it[0] + (it[1] - 1) / 2] == '1')
		return (1);
	return (0);
}

int	check_y_quality(t_global *vars, t_vect *posib, int *it)
{
	if (posib[1].y > 0 && posib[1].y < vars->map_rows
		&& it[0] + (it[1] - 1) / 2 >= 0
		&& it[0] + (it[1] - 1) / 2 < vars->map_rows
		&& (int)floorf(posib[1].x) >= 0
		&& (int)floorf(posib[1].x) < vars->map_columns
		&& vars->map[
			it[0] + (it[1] - 1) / 2][(int)floorf(posib[1].x)] == '1')
		return (1);
	return (0);
}
