/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:22:04 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

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
	start_keys(vars);
	if (!initialize_key_hooks(vars))
		return (0);
	return (1);
}
