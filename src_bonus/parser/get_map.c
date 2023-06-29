/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:23:06 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	put_ones_on_str(char *str, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
	{
		if (str[i] == ' ' || (str[i] != '0' && str[i] != 'N' && str[i] != 'S'
				&& str[i] != 'E' && str[i] != 'W' && str[i] != 'D'))
			str[i] = '1';
	}
	str[i] = '\0';
}

void	read_map_lines(t_global *vars, size_t bggst_line, int rows, char *file)
{
	int		i;
	int		x;
	int		fd;
	char	*line;
	char	*tmp;

	i = -1;
	line = get_first_line_map(file, &fd);
	i = 0;
	while (line && i < rows)
	{
		if (line == NULL)
			break ;
		tmp = line;
		line = ft_strtrim(line, "\n");
		free(tmp);
		x = -1;
		while (line[++x] && line[x] != '\n')
			vars->map[i][x] = line[x];
		put_ones_on_str(vars->map[i], bggst_line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_map_to_matrix(t_global *vars, size_t bggst_l, int rows, char *file)
{
	int	i;

	i = 0;
	vars->map_rows = rows;
	vars->map_columns = (int)bggst_l;
	vars->map = (char **)malloc(sizeof(char *) * (rows + 1));
	while (i < rows)
	{
		vars->map[i] = (char *)malloc(sizeof(char) * bggst_l + 1);
		i++;
	}
	vars->map[rows] = NULL;
	read_map_lines(vars, bggst_l, rows, file);
}

void	get_map(t_global *vars, char *file)
{
	int		fd;
	char	*line;
	int		i;
	size_t	biggest_line_len;
	char	*tmp;

	fd = open(file, O_RDONLY);
	get_text_colors(fd, vars);
	close(fd);
	i = 0;
	biggest_line_len = 0;
	line = get_first_line_map(file, &fd);
	while (line)
	{
		tmp = line;
		line = ft_strtrim(line, "\n");
		free(tmp);
		if (ft_strlen(line) > biggest_line_len)
			biggest_line_len = ft_strlen(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_map_to_matrix(vars, biggest_line_len, i, file);
}
