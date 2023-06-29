/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:05:21 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub_bonus.h"

int	put_map(t_global *vars)
{
	t_image	m_map;

	m_map.img = mlx_new_image(vars->mlx, vars->map_columns * 10,
			vars->map_rows * 10);
	m_map.addr = mlx_get_data_addr(m_map.img, &m_map.bits_per_pixel,
			&m_map.line_length, &m_map.endian);
	scale_map(vars, &m_map, vars->map_columns);
	mlx_put_image_to_window(vars->mlx, vars->win, m_map.img, 0, 0);
	return (1);
}
