/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:14:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub_bonus.h"

void	draw_scaled_pixel(t_image *m_map, int x, int y, t_map map)
{
	int	dy;
	int	dx;

	dy = 0;
	while (dy < map.scale)
	{
		dx = 0;
		while (dx < map.scale)
		{
			my_mlx_pixel_put(m_map, x * map.scale + dx,
				y * map.scale + dy, map.color);
			dx++;
		}
		dy++;
	}
}

void	draw_player(t_global *vars, t_image *m_map, int map_width)
{
	t_vect	vect;
	t_map	map_args;

	map_args.scale = vars->map_columns * 10 / map_width;
	map_args.color = 0x0000FF;
	vect.x = vars->char_pos.x;
	vect.y = vars->char_pos.y;
	draw_line(vars, m_map, vect, map_args);
	map_args.color = 0xFF0000;
	draw_circle(m_map, vect, 5, map_args);
}

void	scale_map2(t_global *vars, t_image *m_map, float scale)
{
	int		y;
	int		x;
	t_map	map;
	t_map	map2;

	map.scale = scale;
	map2.scale = scale;
	map.color = create_trgb(0, 132, 128, 128);
	map2.color = create_trgb(0, 53, 48, 48);
	y = -1;
	while (++y < vars->map_rows)
	{
		x = -1;
		while (++x < vars->map_columns)
		{
			if (vars->map[y][x] != '0' && vars->map[y][x] != '1')
				draw_scaled_pixel(m_map, x, y, map);
			if (vars->map[y][x] == '0')
				draw_scaled_pixel(m_map, x, y, map);
			else if (vars->map[y][x] == '1')
				draw_scaled_pixel(m_map, x, y, map2);
		}
	}
}

void	scale_map(t_global *vars, t_image *m_map, int map_width)
{
	float	scale;

	scale = vars->map_columns * 10 / map_width;
	scale_map2(vars, m_map, scale);
	draw_player(vars, m_map, map_width);
}
