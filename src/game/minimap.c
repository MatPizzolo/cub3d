/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:05:21 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 17:48:43 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void calculate_map_dimensions(t_global *vars, int *map_width, int *map_height)
{
    *map_width = 0;
    *map_height = 0;

    while (vars->map[*map_height])
    {
        int current_row_width = 0;
        while (vars->map[*map_height][current_row_width] && vars->map[*map_height][current_row_width] != '\n')
        {
            current_row_width++;
        }
        if (current_row_width > *map_width)
        {
            *map_width = current_row_width;
        }
        (*map_height)++;
    }
}

void draw_scaled_pixel(t_image *m_map, int x, int y, float scale, int color)
{
    int dy = 0;
    while (dy < scale) // Loop over scaled y-coordinates
    {
        int dx = 0;
        while (dx < scale) // Loop over scaled x-coordinates
        {
            my_mlx_pixel_put(m_map, x * scale + dx, y * scale + dy, color);
            dx++;
        }
        dy++;
    }
}


void scale_minimap(t_global *vars, t_image *m_map, int map_width)
{
    int colors[2];
    colors[0] = create_trgb(0, 255, 255, 255);
    colors[1] = create_trgb(0, 0, 0, 0);

    float scale = 250.0 / map_width; // Calculate the scale factor based on the map's width

    int y = -1;
    while (vars->map[++y])
    {
        int x = -1;
        while (vars->map[y][++x])
        {
            if (vars->map[y][x] == '0')
            {
                draw_scaled_pixel(m_map, x, y, scale, colors[0]);
            }
            else
            {
                draw_scaled_pixel(m_map, x, y, scale, colors[1]);
            }
        }
    }
}

int put_minimap(t_global *vars)
{
    t_image m_map;

    m_map.img = mlx_new_image(vars->mlx, 250, 250);
    m_map.addr = mlx_get_data_addr(m_map.img, &m_map.bits_per_pixel, &m_map.line_length, &m_map.endian);

    int map_width, map_height;
    calculate_map_dimensions(vars, &map_width, &map_height);

    scale_minimap(vars, &m_map, map_width);
	mlx_put_image_to_window(vars->mlx, vars->win, m_map.img, 0, 0);
	return (1);
}