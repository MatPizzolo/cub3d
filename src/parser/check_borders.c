/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:34:26 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/20 22:18:32 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	put_ones(char *str, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
	{
		if (str[i] == ' ')
			str[i] = '1';
	}
	str[i] = '\0';
}

void	read_lines(char **matrix, size_t bggst_line, int rows, char *file)
{
	int		i;
	int		x;
	int		fd;
	char	*line;

	i = -1;
	fd = open(file, O_RDONLY);
	while (line && ft_strichr_sp(line, '1', 1) == 0)
		line = get_next_line(fd);
	i = 0;
	while (line && i < rows)
	{
		if (line == NULL)
			break ;
		line = ft_strtrim(line, "\n");
		x = -1;
		while (line[++x] && line[x] != '\n')
			matrix[i][x] = line[x];
		put_ones(matrix[i], bggst_line);
		i++;
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
	read_lines(*matrix, columns, rows, file);
}

size_t	get_biggest_line(char *file, int *rows)
{
	size_t	biggest_line_len;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (ft_strichr_sp(line, '0', 1) == 0 && ft_strichr_sp(line, '1', 1) == 0)
		line = get_next_line(fd);
	*rows = 1;
	biggest_line_len = 0;
	while (line)
	{
		line = get_next_line(fd);
		line = ft_strtrim(line, "\n");
		if (ft_strlen(line) > biggest_line_len)
			biggest_line_len = ft_strlen(line);
		if (line != NULL)
		{	
			free(line);
			*rows += 1;
		}
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
	if (!check_borders2(matrix, columns, rows))
	{
		printf("Error\nWalls not placed correctly\n");
		return (0);
	}
	if (!check_diff_chars(matrix, columns, rows))
	{
		printf("Error\nA non valid char is present\n");
		return (0);
	}
	return (1);
}
