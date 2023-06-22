/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:20:06 by amejia            #+#    #+#             */
/*   Updated: 2023/06/21 20:40:37 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	game_loop(void *param)
{
	t_global	*vars;
	t_image		img;

	vars = (t_global *)param;
	img.img = mlx_new_image(vars->mlx, SIZE_X, SIZE_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	key_actions(vars);
	mouse_move(vars);
	draw_background(vars, &img);
	mega_wall_render(vars, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
	if (!put_map(vars))
		return (1);
	return (0);
}
