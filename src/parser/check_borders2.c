/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:21:47 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 16:14:24 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	put_x(char *str, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
	{
		if (str[i] != '0' && str[i] != '1')
			str[i] = 'x';
	}
	str[i] = '\0';
}

int	ft_strichr_sp(const char *s, int c, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j] == ' ')
		j++;
	while (s[i] && i - j < len)
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (1);
		i--;
	}
	return (0);
}

int	check_surounded(char **matrix, int y, int x, t_vect max)
{
	if (y == 12 && x >= 25)
		ft_isalpha('a');
	if (y -1 < 0 || x - 1 < 0 || y + 1 >= max.y || x + 1 >= max.x)
		return (1);
	if (y - 1 > 0 && matrix[y - 1][x] != '0' && matrix[y - 1][x] != '1')
		return (0);
	if (matrix[y + 1][x] && matrix[y + 1][x] != '0' && matrix[y + 1][x] != '1')
		return (0);
	if (x - 1 > 0 && matrix[y][x - 1] != '0' && matrix[y][x - 1] != '1')
		return (0);
	if (matrix[y][x + 1] && matrix[y][x + 1] != '0' && matrix[y][x + 1] != '1')
		return (0);
	return (1);
}

int	explore_board(char **matrix, t_vect max)
{
	int	y;
	int	x;

	y = -1;
	while (matrix[++y])
		put_x(matrix[y], max.x);
	y = -1;
	while (matrix[++y])
	{
		x = -1;
		while (matrix[y][++x])
		{
			if (matrix[y][x] == '0')
			{
				if (!check_surounded(matrix, y, x, max))
					return (0);
			}
		}
	}
	return (1);
}

int	check_borders2(char **matrix, size_t columns, int rows)
{
	int		*p_pos;
	t_vect	max;

	max.y = rows;
	max.x = columns;
	p_pos = where_is_p(matrix);
	matrix[p_pos[0]][p_pos[1]] = '0';
	free(p_pos);
	if (!explore_board(matrix, max))
		return (0);
	return (1);
}
