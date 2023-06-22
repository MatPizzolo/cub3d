/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:34:48 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 16:14:09 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	check_color(char *line)
{
	char	**colors;
	int		i;
	int		res;

	res = 1;
	i = 0;
	line += 2;
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
