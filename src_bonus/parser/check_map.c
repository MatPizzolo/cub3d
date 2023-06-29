/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:55:18 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:47:09 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	check_texture(char *line)
{
	char	*tmp_free;	
	int		fd;

	line += 2;
	while (ft_isspace(line[0]))
		line++;
	tmp_free = ft_strtrim(line, "\n");
	fd = open(tmp_free, O_RDONLY);
	if (fd == -1)
		return (free(tmp_free), 0);
	close(fd);
	free(tmp_free);
	return (1);
}

int	print_msg_checker_map(char *line)
{
	char	*tmp;

	tmp = line;
	line = ft_strtrim(line, "\n");
	free(tmp);
	printf("Error\n%s not valid\n", line);
	free(line);
	return (0);
}

int	check_for_textures(char *line, t_parser *pars)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		if (!check_texture(line))
			return (print_msg_checker_map(line));
		pars->no_texture += 1;
	}
	if (!ft_strncmp(line, "SO", 2))
	{
		if (!check_texture(line))
			return (print_msg_checker_map(line));
		pars->so_texture += 1;
	}
	if (!ft_strncmp(line, "WE", 2))
	{
		if (!check_texture(line))
			return (print_msg_checker_map(line));
		pars->we_texture += 1;
	}
	if (!ft_strncmp(line, "EA", 2))
	{
		if (!check_texture(line))
			return (print_msg_checker_map(line));
		pars->ea_texture += 1;
	}
	return (1);
}

int	check_no_map(int fd, t_parser *pars)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!check_for_textures(line, pars))
			return (0);
		if (!check_for_colors(line, pars))
			return (0);
		else
		{
			if (!check_map_before(line, pars))
				return (free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	check_map(char *file)
{
	int			fd;
	t_parser	pars;

	fd = open(file, O_RDONLY);
	initialize_pars_struct(&pars);
	if (!check_no_map(fd, &pars))
		return (0);
	if (!check_pars_struct(pars))
		return (printf("Error\nTextures/colors not okay\n"), 0);
	close(fd);
	fd = open(file, O_RDONLY);
	if (!one_player(fd))
		return (0);
	close(fd);
	if (!check_borders(file))
		return (0);
	return (1);
}
