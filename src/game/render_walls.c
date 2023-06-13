/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:58:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/13 17:33:47 by amejia           ###   ########.fr       */
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


// void    render_wall_col(t_global *vars, t_wall_rend *p)
// {
// 	t_image	mlx_n_image;
// 	t_color	color;
// 	int y;
// 	float ratio;

// 	ratio = (float)p->n_wall->height/p->size;
// 	mlx_n_image.img = mlx_new_image(vars->mlx,1,p->size);
// 	mlx_n_image.addr = mlx_get_data_addr(mlx_n_image.img,
// 		&mlx_n_image.bits_per_pixel, &mlx_n_image.line_length, &mlx_n_image.endian);
// 	y = 0;
// 	while (y < p->size)
// 	{
// 		if (p->n_wall->endian == 1)
// 		{
// 			color.t = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) + p->column ];
// 			color.r = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) + p->column + 1];
// 			color.g = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) + p->column+ 2];
// 			color.b = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) + p->column +  3];
// 		}	
// 		else
// 		{
// 			color.t = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) + p->column +  3];
// 			color.r = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) + p->column +  2];
// 			color.g = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) + p->column +  1];
// 			color.b = (int)p->n_wall->addr[((int)(y*ratio) * p->n_wall->line_length) + p->column ];
// 		}
// 		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
// 		my_mlx_pixel_put(&mlx_n_image, 0, y, color.trgb);
// 		y++;
// 	}
// 	mlx_put_image_to_window(vars->mlx, vars->win, mlx_n_image.img, p->position[0],
// 		p->position[1]);
// }


void    render_wall_col(t_global *vars, int column, int size, int *position)
{
	t_image	n_wall;
	t_image	mlx_n_image;
	t_color	color;
	int y;
	float ratio;

	n_wall.img = mlx_xpm_file_to_image(vars->mlx, vars->NO_texture->file, &n_wall.width, &n_wall.height);
	n_wall.addr = mlx_get_data_addr(n_wall.img, &n_wall.bits_per_pixel, &n_wall.line_length, &n_wall.endian);
	ratio = (float)n_wall.height/size;
	mlx_n_image.img = mlx_new_image(vars->mlx, 1, size);
	mlx_n_image.addr = mlx_get_data_addr(mlx_n_image.img, &mlx_n_image.bits_per_pixel, &mlx_n_image.line_length, &mlx_n_image.endian);
   
	// while (x < n_wall.width* 4)
	// {
   	y = 0;
	while (y < size)
	{
		if (n_wall.endian == 1)
		{
			color.t = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column ];
			color.r = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column + 1];
			color.g = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column+ 2];
			color.b = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column +  3];
		}
		else
		{
			color.t = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column +  3];
			color.r = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column +  2];
			color.g = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column +  1];
			color.b = (int)n_wall.addr[((int)(y*ratio) * n_wall.line_length) + column ];
		}
		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
		my_mlx_pixel_put(&mlx_n_image, 0, y, color.trgb);
		y++;
	}
	//	posx++;
	//	x+= 4;
	// }
	mlx_put_image_to_window(vars->mlx, vars->win, mlx_n_image.img, position[0], position[1]);
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
	int pos[2];
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
		
		p.position[0] =  400+count;//960 + sinf(theta)/sin(FOV/2) * 960;
		p.size = 50;
		p.position[1] = 540;
		pos[0] = p.position[0];
		pos[1] = p.position[1];
		p.n_wall = n_wall;
		if (p.position[0] > 0 && p.position[0] < 1080)
			render_wall_col(vars,count,p.size,pos);
		current += STEP_S;
		count ++;
	}
	
}