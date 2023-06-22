/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:10:27 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/21 20:38:50 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_free_split(char **split)
{
	int	ct;

	ct = 0;
	while (split[ct] != 0)
	{
		free(split[ct]);
		ct++;
	}
	free(split);
}

int	close_window(t_global *vars)
{
	ft_free_split(vars->map);
	free(vars->ea_texture);
	free(vars->we_texture);
	free(vars->no_texture);
	free(vars->so_texture);
	free(vars->keys);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
