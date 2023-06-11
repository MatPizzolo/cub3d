/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:55:18 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/11 22:30:02 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	check_texture(int fd, char *texture)
{
	char	*line;
	char	*tmp_free;	
	
	line = get_next_line(fd);
	tmp_free = ft_substr(line, 0, 2);
	if (ft_strncmp(texture, tmp_free, 2))
	{
		printf("%s, texture not found\n", texture);	
		return (0);
	}
	free(tmp_free);
	// tmp_free = ft_strtrim((line + 3), "\n");
	// if (open(tmp_free, O_RDONLY) == -1)
	// 	return (0);
	// free(tmp_free);
	return (1);
}

int	are_textures(int fd)
{
	if (!check_texture(fd, "NO"))
		return (0);
	if (!check_texture(fd, "SO"))
		return (0);
	if (!check_texture(fd, "WE"))
		return (0);
	if (!check_texture(fd, "EA"))
		return (0);
	return (1);
}

int	are_colors(int fd)
{
	char	*line;

	line = get_next_line(fd);
	line = get_next_line(fd);
	if (line[0] != 'F')
	{
		printf("Floor color not found\n");
		return (0);
	}
	line = get_next_line(fd);
	if (line[0] != 'C')
	{
		printf("Ceiling color not found\n");
		return (0);
	}
	return (1);
}

int	one_player(int fd)
{
	fd += 0;
	return (1);
}

int	check_map(t_global *vars, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (!are_textures(fd))
		return (0);
	if (!are_colors(fd))
		return (0);
	if (!one_player(fd))
		return (0);
	if (!is_playable(vars, fd))
		return (0);
	close(fd);
	return (1);
}
