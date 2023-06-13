/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:58:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/13 15:23:01 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void endian1_color_asign(t_color *color, t_wall_rend *p, int y, float ratio)
{
	color->t = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column ];
	color->r = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column + 1];
	color->g = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column+ 2];
	color->b = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column +  3];
}


void else_color_asign(t_color *color, t_wall_rend *p, int y, float ratio)
{
	color->t = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column +  3];
	color->r = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column +  2];
	color->g = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column +  1];
	color->b = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) 
		+ p->column ];
}


void    render_wall_col(t_global *vars, t_wall_rend *p)
{
	t_image	mlx_n_image;
	t_color	color;
	int y;
	float ratio;

	ratio = (float)p->n_wall->height/p->size;
	mlx_n_image.img = mlx_new_image(vars->mlx,1,p->size);
	mlx_n_image.addr = mlx_get_data_addr(mlx_n_image.img,
		&mlx_n_image.bits_per_pixel, &mlx_n_image.line_length, &mlx_n_image.endian);
	y = 0;
	while (y < p->size)
	{
		if (p->n_wall->endian == 1)
			endian1_color_asign(&color, p, y, ratio);
		else
			else_color_asign(&color, p, y, ratio);
		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
		my_mlx_pixel_put(&mlx_n_image, 0, y, color.trgb);
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, mlx_n_image.img, p->position[0],
		p->position[1]);
}


// wall contains director in 0, current position in 1 and direct ffrom player in 2
void render_wall(t_global *vars,t_vect cor1, t_vect cor2, t_image *n_wall)
{
	t_vect wall[3];
	// float		walldir[2];
	// float		wallpos[2];
	float		current;
	t_wall_rend	p;
	// float		vector2me[2];
	int count = 0;
	float theta;

	// neg_v(cor1);
	// add_v(cor2, cor1, walldir);
	wall[0] = sub_v(cor2, cor1);
	current = 0;
	while (current < 1)
	{
		wall[1] = add_v(cor1, f_x_v(current, wall[0]));
		// wallpos[0] = cor1[0] + current * walldir[0];
		// wallpos[1] = cor1[1] + current * walldir[1];
		wall[2] = sub_v(wall[1],vars->char_pos);		
		// vector2me[0] = walldir[0] - vars->char_pos.y;
		// vector2me[1] = walldir[1] - vars->char_pos.x;
		theta =acosf(dot_prod(wall[2], vars->char_facing) / size_vect(wall[2]));
		p.column = count;
		
		p.position[0] =  960 + sinf(theta)/sin(FOV/2) * 960;
		p.position[1] = 540;
		p.n_wall = n_wall;
		render_wall_col(vars,&p);
		current += STEP_S;
		count ++;
	}
	
}