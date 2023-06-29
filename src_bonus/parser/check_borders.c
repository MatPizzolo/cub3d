/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:34:26 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	put_ones_mtx(char **mtx, size_t len)
{
	size_t	x;
	int		y;
	char	*str;

	y = -1;
	while (mtx[++y])
	{
		str = mtx[y];
		x = -1;
		while (++x < len)
		{
			if (str[x] != '0')
				str[x] = '1';
		}
		str[x] = '\0';
	}
}

void	read_lines(char **matrix, size_t bggst_line, char *file)
{
	int		i;
	int		x;
	int		fd;
	char	*line;
	char	*tmp;

	line = get_first_line_map(file, &fd);
	i = 0;
	while (line)
	{
		if (line == NULL)
			break ;
		tmp = line;
		line = ft_strtrim(line, "\n");
		free(tmp);
		x = -1;
		while (line[++x] && line[x] != '\n')
			matrix[i][x] = line[x];
		matrix[i][x] = '\0';
		bggst_line += 0;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_matrix(char ***matrix, size_t columns, int rows, char *file)
{
	int	i;

	i = 0;
	(*matrix) = (char **)malloc(sizeof(char *) * (rows + 1));
	while (i < rows)
	{
		(*matrix)[i] = (char *)malloc(sizeof(char) * columns + 1);
		i++;
	}
	(*matrix)[rows] = NULL;
	read_lines(*matrix, columns, file);
}

size_t	get_biggest_line(char *file, int *rows)
{
	size_t	biggest_line_len;
	char	*line;
	int		fd;
	char	*tmp;

	line = get_first_line_map(file, &fd);
	*rows = 0;
	biggest_line_len = 0;
	while (line)
	{
		tmp = line;
		line = ft_strtrim(line, "\n");
		free(tmp);
		if (ft_strlen(line) > biggest_line_len)
			biggest_line_len = ft_strlen(line);
		if (line != NULL)
		{	
			free(line);
			*rows += 1;
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (biggest_line_len);
}

int	check_borders(char *file)
{
	size_t	columns;
	int		rows;
	char	**matrix;

	columns = get_biggest_line(file, &rows);
	get_matrix(&matrix, columns, rows, file);
	if (!check_diff_chars(matrix))
	{
		printf("Error\nA non valid char is present\n");
		return (ft_free_split(matrix), 0);
	}
	if (!check_borders2(matrix, columns, rows))
	{
		printf("Error\nWalls not placed correctly\n");
		return (ft_free_split(matrix), 0);
	}
	put_ones_mtx(matrix, columns);
	if (!check_borders_a(matrix, columns, rows))
	{
		printf("Error\nWalls not placed correctly\n");
		return (ft_free_split(matrix), 0);
	}
	return (ft_free_split(matrix), 1);
}
