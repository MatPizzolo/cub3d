/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:40:13 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:46:44 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	put_f_color(t_global *vars, char *line)
{
	char	**colors;

	line += 1;
	while (ft_isspace(line[0]))
		line++;
	colors = ft_split(line, ',');
	vars->floor_color[0] = ft_atoi(colors[0]);
	free(colors[0]);
	vars->floor_color[1] = ft_atoi(colors[1]);
	free(colors[1]);
	vars->floor_color[2] = ft_atoi(colors[2]);
	free(colors[2]);
	free(colors);
}

void	put_c_color(t_global *vars, char *line)
{
	char	**colors;

	line += 1;
	while (ft_isspace(line[0]))
		line++;
	colors = ft_split(line, ',');
	vars->ceiling_color[0] = ft_atoi(colors[0]);
	free(colors[0]);
	vars->ceiling_color[1] = ft_atoi(colors[1]);
	free(colors[1]);
	vars->ceiling_color[2] = ft_atoi(colors[2]);
	free(colors[2]);
	free(colors);
}

void	get_text_colors(int fd, t_global *vars)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "NO", 2))
			texture_no(line, vars);
		else if (!ft_strncmp(line, "SO", 2))
			texture_so(line, vars);
		else if (!ft_strncmp(line, "EA", 2))
			texture_ea(line, vars);
		else if (!ft_strncmp(line, "WE", 2))
			texture_we(line, vars);
		else if (!ft_strncmp(line, "F", 1))
			put_f_color(vars, line);
		else if (!ft_strncmp(line, "C", 1))
			put_c_color(vars, line);
		free(line);
		line = get_next_line(fd);
	}
}
