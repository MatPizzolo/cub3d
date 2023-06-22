/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:47:58 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 16:11:08 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

char	*get_first_line_map_fd(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && ft_strichr_sp(line, '1', 1) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

int	one_player(int fd)
{
	int		player;
	int		i;
	char	*line;

	player = 0;
	line = get_first_line_map_fd(fd);
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'W' || line[i] == 'E')
				player++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (player > 1 || player == 0)
		return (printf("Error\nMore than one player or none\n"), 0);
	return (1);
}

int	check_map_before(char *line, t_parser *p)
{
	int	i;
	int	res;

	res = 0;
	if (p->c_color == 0 && p->f_color == 0 && p->no_texture == 0
		&& p->so_texture == 0 && p->we_texture == 0 && p->ea_texture == 0)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == '1' || line[i] == '0')
				res++;
		}
	}
	if (res > 3)
	{
		printf("Error\nMap canot be before identifiers\n");
		return (0);
	}
	return (1);
}

void	initialize_pars_struct(t_parser *pars)
{
	pars->c_color = 0;
	pars->f_color = 0;
	pars->no_texture = 0;
	pars->so_texture = 0;
	pars->we_texture = 0;
	pars->ea_texture = 0;
}

int	check_pars_struct(t_parser pars)
{
	if (pars.c_color != 1)
		return (0);
	if (pars.f_color != 1)
		return (0);
	if (pars.no_texture != 1)
		return (0);
	if (pars.so_texture != 1)
		return (0);
	if (pars.we_texture != 1)
		return (0);
	if (pars.ea_texture != 1)
		return (0);
	return (1);
}
