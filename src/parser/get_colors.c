/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:22:32 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/20 21:33:29 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	put_f_color(t_global *vars, char *line)
{
	char	**colors;

	colors = ft_split(line, ',');
	vars->floor_color[0] = ft_atoi(colors[0]);
	vars->floor_color[1] = ft_atoi(colors[1]);
	vars->floor_color[2] = ft_atoi(colors[2]);
}

void	put_c_color(t_global *vars, char *line)
{
	char	**colors;

	colors = ft_split(line, ',');
	vars->ceiling_color[0] = ft_atoi(colors[0]);
	vars->ceiling_color[1] = ft_atoi(colors[1]);
	vars->ceiling_color[2] = ft_atoi(colors[2]);
}

void	get_colors(t_global *vars, int fd)
{
	char	*line;
	int		x;

	x = 0;
	line = get_next_line(fd);
	while (line[0] != 'F' && line[0] != 'C')
		line = get_next_line(fd);
	if (line[0] == 'F')
		x = 1;
	line += 2;
	if (x == 1)
		put_f_color(vars, line);
	else
		put_c_color(vars, line);
	line = get_next_line(fd);
	line += 2;
	if (x == 0)
		put_f_color(vars, line);
	else
		put_c_color(vars, line);
}
