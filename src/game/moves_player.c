/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:58:42 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/19 22:27:05 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	move_view(int view_to, t_global *vars)
{
	if (view_to == 2)
		vars->char_facing = rotate_vector(vars->char_facing, -PI / 28);
	else if (view_to == 1)
		vars->char_facing = rotate_vector(vars->char_facing, PI / 28);
	put_map(vars);
}

void	move_player(int move_to, t_global *vars)
{
	t_vect	tmp;
	char	next_position;

	tmp.x = vars->char_pos.x;
	tmp.y = vars->char_pos.y;
	if (move_to == 1)
		tmp = add_v(vars->char_pos,
				f_x_v(0.05, rotate_vector(vars->char_facing, -PI / 2)));
	else if (move_to == 2)
		tmp = add_v(vars->char_pos,
				f_x_v(0.05, rotate_vector(vars->char_facing, PI / 2)));
	else if (move_to == 3)
		tmp = add_v(vars->char_pos,
				f_x_v(0.05, rotate_vector(vars->char_facing, PI)));
	else if (move_to == 4)
		tmp = add_v(vars->char_pos, f_x_v(0.05, vars->char_facing));
	if (tmp.x < 0 || tmp.y < 0)
		return ;
	if (!vars->map[(int)roundf(tmp.y)][(int)roundf(tmp.x)])
		return ;
	next_position = vars->map[(int)floorf(tmp.y)][(int)floorf(tmp.x)];
	if (next_position == '1')
		return ;
	vars->char_pos = tmp;
	put_map(vars);
}
