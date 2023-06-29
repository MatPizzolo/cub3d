/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:26:27 by amejia            #+#    #+#             */
/*   Updated: 2023/06/22 17:09:40 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	endian1_color_asign(t_color *color, t_wall_rend *p, int y, float rat)
{
	color->t = (int)p->n_wall->addr[((int)(y * rat) *(p->n_wall->line_length))
		+ p->column];
	color->r = (int)p->n_wall->addr[((int)(y * rat) *(p->n_wall->line_length))
		+ p->column + 1];
	color->g = (int)p->n_wall->addr[((int)(y * rat) *(p->n_wall->line_length))
		+ p->column + 2];
	color->b = (int)p->n_wall->addr[((int)(y * rat) *(p->n_wall->line_length))
		+ p->column + 3];
}

void	else_color_asign(t_color *color, t_wall_rend *p, int y, float ratio)
{
	color->t = (unsigned char)p->n_wall->addr[((int)(y * ratio)
			*p->n_wall->line_length) + 4 * p->column + 3];
	color->r = (unsigned char)p->n_wall->addr[((int)(y * ratio)
			*p->n_wall->line_length) + 4 * p->column + 2];
	color->g = (unsigned char)p->n_wall->addr[((int)(y * ratio)
			*p->n_wall->line_length) + 4 * p->column + 1];
	color->b = (unsigned char)p->n_wall->addr[((int)(y * ratio)
			*p->n_wall->line_length) + 4 * p->column];
}

void	render_wall_col(t_wall_rend *p)
{
	t_color	color;
	int		y;
	float	ratio;

	ratio = (float)p->n_wall->height / p->size;
	y = 0;
	while (y < p->size)
	{
		if (p->position[0] < 0 || p->position[0] >= SIZE_X)
			break ;
		if (p->position[1] + y < 0 || p->position[1] + y >= SIZE_Y)
		{
			y++;
			continue ;
		}
		if (p->n_wall->endian == 1)
			endian1_color_asign(&color, p, y, ratio);
		else
			else_color_asign(&color, p, y, ratio);
		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
		my_mlx_pixel_put(p->img_dst, p->position[0], p->position[1] + y,
			color.trgb);
		y++;
	}
}

void	mega_wall_render(t_global *vars, t_image *img)
{
	int		ct[5];
	t_vect	intersect;

	ft_bzero(ct, 5);
	while (ct[0] < SIZE_X)
	{
		intersect = calc_ray_intersect(vars, ct[0], &ct[1]);
		if (dist_vec(intersect, set_vect(-1, -1)) != 0)
		{
			ct[3] = ct[0];
			ct[4] = SIZE_Y / 2 - W_SIZE / 2 / (dist_vec(vars->char_pos,
						intersect) + 0.1);
			if (ct[1] == 0)
				ct[2] = (int)(50 * (intersect.y - floorf(intersect.y)));
			else if (ct[1] == 1)
				ct[2] = (int)(50 * (intersect.x - floorf(intersect.x)));
			if (ct[1] != -1)
				render_wall_col_setup(vars, ct, img, intersect);
		}
		ct[0]++;
	}
}
