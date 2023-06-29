/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:44:30 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:47:35 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	texture_no(char *line, t_global *vars)
{
	t_image	*tmp_no;

	tmp_no = (t_image *)malloc(sizeof(t_image));
	line += 2;
	while (ft_isspace(line[0]))
		line++;
	tmp_no->file = ft_strtrim(line, "\n");
	tmp_no->img = mlx_xpm_file_to_image(vars->mlx, tmp_no->file,
			&tmp_no->width, &tmp_no->height);
	tmp_no->addr = mlx_get_data_addr(tmp_no->img, &tmp_no->bits_per_pixel,
			&tmp_no->line_length, &tmp_no->endian);
	vars->no_texture = tmp_no;
	free(tmp_no->file);
}

void	texture_so(char *line, t_global *vars)
{
	t_image	*tmp_so;

	tmp_so = (t_image *)malloc(sizeof(t_image));
		line += 2;
	while (ft_isspace(line[0]))
		line++;
	tmp_so->file = ft_strtrim(line, "\n");
	tmp_so->img = mlx_xpm_file_to_image(vars->mlx, tmp_so->file,
			&tmp_so->width, &tmp_so->height);
	tmp_so->addr = mlx_get_data_addr(tmp_so->img, &tmp_so->bits_per_pixel,
			&tmp_so->line_length, &tmp_so->endian);
	vars->so_texture = tmp_so;
	free(tmp_so->file);
}

void	texture_we(char *line, t_global *vars)
{
	t_image	*tmp_we;

	tmp_we = (t_image *)malloc(sizeof(t_image));
	line += 2;
	while (ft_isspace(line[0]))
		line++;
	tmp_we->file = ft_strtrim(line, "\n");
	tmp_we->img = mlx_xpm_file_to_image(vars->mlx, tmp_we->file,
			&tmp_we->width, &tmp_we->height);
	tmp_we->addr = mlx_get_data_addr(tmp_we->img, &tmp_we->bits_per_pixel,
			&tmp_we->line_length, &tmp_we->endian);
	vars->we_texture = tmp_we;
	free(tmp_we->file);
}

void	texture_ea(char *line, t_global *vars)
{
	t_image	*tmp_ea;

	tmp_ea = (t_image *)malloc(sizeof(t_image));
		line += 2;
	while (ft_isspace(line[0]))
		line++;
	tmp_ea->file = ft_strtrim(line, "\n");
	tmp_ea->img = mlx_xpm_file_to_image(vars->mlx, tmp_ea->file,
			&tmp_ea->width, &tmp_ea->height);
	tmp_ea->addr = mlx_get_data_addr(tmp_ea->img, &tmp_ea->bits_per_pixel,
			&tmp_ea->line_length, &tmp_ea->endian);
	vars->ea_texture = tmp_ea;
	free(tmp_ea->file);
}
