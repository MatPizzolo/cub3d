/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap-utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:59:34 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub_bonus.h"

void	draw_line(t_global *vars, t_image *m_map, t_vect vect, t_map map)
{
	float	dx;
	float	to_x;
	float	to_y;

	dx = 0;
	norm_vect(vars->char_facing);
	to_x = vars->char_facing.x;
	to_y = vars->char_facing.y;
	while (dx < 10 && dx >= 0)
	{
		my_mlx_pixel_put(m_map, (vect.x * map.scale) + (dx * to_x),
			(vect.y * map.scale) + (dx * to_y), map.color);
		dx += 0.25;
	}
}

void	draw_circle_util(t_image *m_map, t_vect cntr, t_vect pos, t_map map)
{
	my_mlx_pixel_put(m_map, cntr.x + pos.x, cntr.y + pos.y, map.color);
	my_mlx_pixel_put(m_map, cntr.x + pos.y, cntr.y + pos.x, map.color);
	my_mlx_pixel_put(m_map, cntr.x - pos.y, cntr.y + pos.x, map.color);
	my_mlx_pixel_put(m_map, cntr.x - pos.x, cntr.y + pos.y, map.color);
	my_mlx_pixel_put(m_map, cntr.x - pos.x, cntr.y - pos.y, map.color);
	my_mlx_pixel_put(m_map, cntr.x - pos.y, cntr.y - pos.x, map.color);
	my_mlx_pixel_put(m_map, cntr.x + pos.y, cntr.y - pos.x, map.color);
	my_mlx_pixel_put(m_map, cntr.x + pos.x, cntr.y - pos.y, map.color);
}

void	draw_circle(t_image *m_map, t_vect vect, int radius, t_map map)
{
	t_vect	cntr;
	t_vect	pos;
	float	radius_error;

	cntr.x = vect.x * map.scale;
	cntr.y = vect.y * map.scale;
	pos.x = radius;
	pos.y = 0;
	radius_error = 1 - pos.x;
	while (pos.x >= pos.y)
	{
		draw_circle_util(m_map, cntr, pos, map);
		pos.y++;
		if (radius_error < 0)
		{
			radius_error += 2 * pos.y + 1;
		}
		else
		{
			pos.x--;
			radius_error += 2 * (pos.y - pos.x + 1);
		}
	}
}
