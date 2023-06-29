/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:58:48 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 16:06:58 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	check_borders_a(char **matrix, size_t columns, int rows)
{
	int		row;
	size_t	col;

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

int	check_diff_chars(char **matrix)
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
				&& c != 'W' && c != 'E' && c != 'S' && c != ' ')
				return (0);
		}
	}
	return (1);
}

char	*get_first_line_map(char *file, int *fd)
{
	char	*line;

	*fd = open(file, O_RDONLY);
	line = get_next_line(*fd);
	while (ft_strichr_sp(line, '0', 1) == 0 && ft_strichr_sp(line, '1', 1) == 0)
	{	
		free(line);
		line = get_next_line(*fd);
	}
	return (line);
}
