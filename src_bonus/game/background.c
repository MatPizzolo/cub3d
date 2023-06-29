/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:19:51 by amejia            #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	draw_background(t_global *vars, t_image *img)
{
	int	x[2];
	int	n;
	int	c_color;
	int	f_color;

	c_color = create_trgb(0, vars->ceiling_color[0],
			vars->ceiling_color[1], vars->ceiling_color[2]);
	f_color = create_trgb(0, vars->floor_color[0],
			vars->floor_color[1], vars->floor_color[2]);
	ft_bzero(x, 2 * sizeof(int));
	while (++x[0] < SIZE_X)
	{
		x[1] = 0;
		while (++x[1] < (int)SIZE_Y)
		{
			if (x[1] > (int)SIZE_Y / 2)
				n = f_color;
			else
				n = c_color;
			my_mlx_pixel_put(img, x[0], x[1], n);
		}
	}
}
