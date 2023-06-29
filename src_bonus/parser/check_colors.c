/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:34:48 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:51:13 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

int	check_color(char *line)
{
	char	**colors;
	int		i;
	int		res;

	res = 1;
	i = 0;
	line += 1;
	while (ft_isspace(line[0]))
		line++;
	colors = ft_split(line, ',');
	while (i < 3)
	{
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
			res = 0;
		free(colors[i]);
		i++;
	}
	free(colors);
	return (res);
}

int	check_for_colors(char *line, t_parser *pars)
{
	if (!ft_strncmp(line, "F", 1))
	{
		if (!check_color(line))
			return (print_msg_checker_map(line));
		pars->f_color += 1;
	}
	if (!ft_strncmp(line, "C", 1))
	{
		if (!check_color(line))
			return (print_msg_checker_map(line));
		pars->c_color += 1;
	}
	return (1);
}

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
