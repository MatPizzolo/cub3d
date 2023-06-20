/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:34:48 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/20 21:51:26 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	are_colors(int fd)
{
	char	*line;
	int		x;

	x = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'F')
		{
			x = 1;
			break ;
		}
		if (line[0] == 'C')
		{
			x = -1;
			break ;
		}
		line = get_next_line(fd);
	}
	if (line == NULL)
		printf("Error\nNo colors found\n");
	line = get_next_line(fd);
	if (line[0] != 'C' && line[0] != 'F')
	{
		if (x == 1 && line[0] != 'C')
			return (printf("Error\nCeiling color not found\n"), 0);
		if (x == -1 && line[0] != 'F')
			return (printf("Error\nFloor color not found\n"), 0);
		if (line[0] == 'F')
			x += 1;
		if (line[0] == 'C')
			x += -1;
	}
	if (x < -1 || x > 1)
		printf("Error\nRepeated color found\n");
	return (1);
}
