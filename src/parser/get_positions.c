/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:57:38 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/21 19:11:48 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	*where_is_p(char **matrix)
{
	int	*p_pos;
	int	y;
	int	x;

	p_pos = (int *)malloc(2 * sizeof(int));
	if (!p_pos)
		return (0);
	y = -1;
	x = 0;
	while (matrix[++y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'N' || matrix[y][x] == 'E' || matrix[y][x]
				== 'S' || matrix[y][x] == 'W')
			{
				p_pos[0] = y;
				p_pos[1] = x;
				return (p_pos);
			}
			x++;
		}
	}
	return (p_pos);
}

void	put_facing(t_global *vars, char c)
{
	if (c == 'N')
	{	
		vars->char_facing.y = -1;
		vars->char_facing.x = 0;
	}
	else if (c == 'S')
	{	
		vars->char_facing.y = 1;
		vars->char_facing.x = 0;
	}
	else if (c == 'E')
	{	
		vars->char_facing.y = 0;
		vars->char_facing.x = 1;
	}
	else if (c == 'W')
	{	
		vars->char_facing.y = 0;
		vars->char_facing.x = -1;
	}
	else if (c == 'D')
		vars->char_facing = set_vect(-1, 1);
}

void	get_positions(t_global *vars)
{
	int		*p_pos;

	p_pos = where_is_p(vars->map);
	put_facing(vars, vars->map[p_pos[0]][p_pos[1]]);
	vars->char_pos.y = p_pos[0] + 0.5;
	vars->char_pos.x = p_pos[1] + 0.5;
	free(p_pos);
}
