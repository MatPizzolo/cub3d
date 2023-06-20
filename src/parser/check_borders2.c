/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:21:47 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/20 21:12:08 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

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

int	check_borders2(char **matrix, size_t columns, int rows)
{
	int	row;
	int	col;

	col = 0;
	while (col < columns)
	{
		if (matrix[0][col] != '1')
			return (0);
		if (matrix[rows - 1][col] != '1')
			return (0);
		++col;
	}
	row = 0;
	while (row < rows)
	{
		if (matrix[row][0] != '1')
			return (0);
		if (matrix[row][columns - 1] != '1')
			return (0);
		++row;
	}
	return (1);
}

int	check_diff_chars(char **matrix, size_t columns, int rows)
{
	int		y;
	int		x;
	char	c;

	y = -1;
	while (matrix[++y])
	{
		x = -1;
		while (matrix[y][++x])
		{
			c = matrix[y][x];
			if (c != '0' && c != '1' && c != 'N'
				&& c != 'W' && c != 'E' && c != 'S')
				return (0);
		}
	}
	return (1);
}
