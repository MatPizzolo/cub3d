/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap-utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:59:34 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/20 16:13:55 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub.h"

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

void	draw_circle(t_image *m_map, t_vect vect, int radius, t_map map)
{
	float	scld_cntrx;
	float	scld_cntr_y;
	float	x;
	float	y;
	float	radius_error;

	scld_cntrx = vect.x * map.scale;
	scld_cntr_y = vect.y * map.scale;
	x = radius;
	y = 0;
	radius_error = 1 - x;
	while (x >= y)
	{
		my_mlx_pixel_put(m_map, scld_cntrx + x, scld_cntr_y + y, map.color);
		my_mlx_pixel_put(m_map, scld_cntrx + y, scld_cntr_y + x, map.color);
		my_mlx_pixel_put(m_map, scld_cntrx - y, scld_cntr_y + x, map.color);
		my_mlx_pixel_put(m_map, scld_cntrx - x, scld_cntr_y + y, map.color);
		my_mlx_pixel_put(m_map, scld_cntrx - x, scld_cntr_y - y, map.color);
		my_mlx_pixel_put(m_map, scld_cntrx - y, scld_cntr_y - x, map.color);
		my_mlx_pixel_put(m_map, scld_cntrx + y, scld_cntr_y - x, map.color);
		my_mlx_pixel_put(m_map, scld_cntrx + x, scld_cntr_y - y, map.color);
		y++;
		if (radius_error < 0)
		{
			radius_error += 2 * y + 1;
		}
		else
		{
			x--;
			radius_error += 2 * (y - x + 1);
		}
	}
}
