/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:40:53 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/14 03:41:16 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

// hay que  hacerlo de manera distinta
// la funcion put_tile esta comentada en mlx_utils.c
// int	put_walls(t_global *vars)
// {
// 	int size[2];
// 	int pos[2];
// 	pos[0] = (int)SIZE_X/2;
// 	pos[1] = (int)SIZE_Y/2;
// 	size[0] = 2000;
// 	size[1] = 2000;
// 	put_tile(vars, pos, size);
// 	return (1);
// }

void	start_keys(t_global *vars)
{
	vars->keys = (t_keys *)malloc(sizeof(t_keys));
	vars->keys->k_a = 0;
	vars->keys->k_w = 0;
	vars->keys->k_s = 0;
	vars->keys->k_d = 0;
	vars->keys->k_l = 0;
	vars->keys->k_r = 0;
	vars->keys->k_esc = 0;
	vars->keys->k_space = 0;
	vars->mouse_pos.x = 0;
	vars->mouse_pos.y = 0;
}

int	initialize_key_hooks(t_global *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_key_hook(vars->win, key_released, vars);
	mlx_loop_hook(vars->mlx, game_loop, (void *)vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop(vars->mlx);
	return (1);
}

int	start_map(t_global *vars, char	*argv)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, SIZE_X, SIZE_Y, "Cub3D");
	get_map(vars, argv);
	get_positions(vars);
	background(vars);
	start_keys(vars);
	if (!put_map(vars))
		return (0);
	if (!initialize_key_hooks(vars))
		return (0);
	return (1);
}
