/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:55:16 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/21 17:02:50 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int	check_extention(char *file)
{
	int	len;
	int	fd;

	len = ft_strlen(file);
	if (file[len - 1] != 'b' || file[len - 2] != 'u'
		|| file[len - 3] != 'c' || file[len - 4] != '.')
	{
		printf("Error\nInvalid extension\n");
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCouldn`t open file\n");
		return (0);
	}
	close(fd);
	return (1);
}

int	check_args(int argc, char *file)
{
	if (argc != 2)
	{
		printf("Error\nInvalid arguments\n");
		return (0);
	}
	if (!check_extention(file))
		return (0);
	return (1);
}
