/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:20:23 by amejia            #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	mouse_move(t_global *vars)
{
	int	x;
	int	y;
	int	res;

	x = 0;
	y = 0;
	mlx_mouse_hide();
	res = mlx_mouse_get_pos(vars->win, &x, &y);
	if (x - vars->mouse_pos.x > 50 || vars->mouse_pos.x - x > 50)
	{	
		if (x - vars->mouse_pos.x > 50)
			move_view(1, vars);
		else
			move_view(2, vars);
		res = mlx_mouse_move(vars->win, 950, 600);
		vars->mouse_pos.x = 950;
	}
}

int	key_actions(t_global *vars)
{
	if (vars->keys->k_esc == 1)
		close_window(vars);
	else if (vars->keys->k_w == 1)
		move_player(4, vars);
	else if (vars->keys->k_s == 1)
		move_player(3, vars);
	else if (vars->keys->k_d == 1)
		move_player(2, vars);
	else if (vars->keys->k_a == 1)
		move_player(1, vars);
	else if (vars->keys->k_r == 1)
		move_view(1, vars);
	else if (vars->keys->k_l == 1)
		move_view(2, vars);
	return (0);
}

int	key_press(int keycode, t_global *vars)
{
	if (keycode == KH_ESC)
		vars->keys->k_esc = 1;
	else if (keycode == KH_W)
		vars->keys->k_w = 1;
	else if (keycode == KH_S)
		vars->keys->k_s = 1;
	else if (keycode == KH_D)
		vars->keys->k_d = 1;
	else if (keycode == KH_A)
		vars->keys->k_a = 1;
	else if (keycode == KH_RK)
		vars->keys->k_r = 1;
	else if (keycode == KH_LK)
		vars->keys->k_l = 1;
	else if (keycode == KH_SPACE)
		vars->keys->k_space = 1;
	return (0);
}

int	key_released(int keycode, t_global *vars)
{
	if (keycode == KH_ESC)
		vars->keys->k_esc = 0;
	else if (keycode == KH_W)
		vars->keys->k_w = 0;
	else if (keycode == KH_S)
		vars->keys->k_s = 0;
	else if (keycode == KH_D)
		vars->keys->k_d = 0;
	else if (keycode == KH_A)
		vars->keys->k_a = 0;
	else if (keycode == KH_RK)
		vars->keys->k_r = 0;
	else if (keycode == KH_LK)
		vars->keys->k_l = 0;
	else if (keycode == KH_SPACE)
		vars->keys->k_space = 0;
	return (0);
}
