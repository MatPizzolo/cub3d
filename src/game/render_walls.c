
#include "../../cub.h"

void	endian1_color_asign(t_color *color, t_wall_rend *p, int y, float rat)
{
	color->t = (int)p->n_wall->addr[((int)(y * rat) * (p->n_wall->line_length))
		+ p->column];
	color->r = (int)p->n_wall->addr[((int)(y * rat) * (p->n_wall->line_length))
		+ p->column + 1];
	color->g = (int)p->n_wall->addr[((int)(y * rat) * (p->n_wall->line_length))
		+ p->column+ 2];
	color->b = (int)p->n_wall->addr[((int)(y * rat) * (p->n_wall->line_length))
		+ p->column + 3];
}

void	else_color_asign(t_color *color, t_wall_rend *p, int y, float ratio)
{
	color->t = (unsigned char)p->n_wall->addr[((int)(y * ratio) 
		* p->n_wall->line_length) + 4 * p->column +  3];
	color->r = (unsigned char)p->n_wall->addr[((int)(y * ratio) 
		* p->n_wall->line_length) + 4 * p->column +  2];
	color->g = (unsigned char)p->n_wall->addr[((int)(y * ratio) 
		* p->n_wall->line_length) + 4 * p->column +  1];
	color->b = (unsigned char)p->n_wall->addr[((int)(y * ratio) 
		* p->n_wall->line_length) + 4 * p->column  ];
}

void	render_wall_col(t_global *vars, t_wall_rend *p)
{
	t_color	color;
	int y;
	float ratio;

	ratio = (float)p->n_wall->height/p->size;
   	y = 0;
	while (y < p->size)
	{
		if (p->position[0] < 0 || p->position[0] >= SIZE_X)
			break ;
		if (p->position[1] + y < 0 || p->position[1] + y >= SIZE_Y)
		{
			y++;
			continue;
		}
		if (p->n_wall->endian == 1)
			endian1_color_asign(&color, p, y ,ratio);
		else
			else_color_asign(&color, p, y, ratio);
		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
		my_mlx_pixel_put(p->img_dst, p->position[0], p->position[1] + y,
			color.trgb);
		y++;
	}
}

void    render_wall_col_old(t_global *vars, int column, int size, int *position, 
	t_image *img)
{
	t_image	n_wall;
	t_image	mlx_n_image;
	t_color	color;
	int y;
	float ratio;
	t_wall_rend p;

	p.column = column;
	p.size = size;
	p.position[0] = position[0];
	p.position[1] = position[1];

	n_wall.img = mlx_xpm_file_to_image(vars->mlx, vars->no_texture->file, &n_wall.width, &n_wall.height);
	n_wall.addr = mlx_get_data_addr(n_wall.img, &n_wall.bits_per_pixel, &n_wall.line_length, &n_wall.endian);
	p.n_wall = &n_wall;
	ratio = (float)n_wall.height/size;
   	y = 0;
	while (y < size)
	{
		if (position[0] < 0 || position[0] >= SIZE_X)
			break ;
		if (position[1] + y < 0 || position[1] + y >= SIZE_Y)
		{
			y++;
			continue;
		}
		if (n_wall.endian == 1)
			endian1_color_asign(&color, &p, y ,ratio);
		else
			else_color_asign(&color, &p, y, ratio);
		color.trgb = create_trgb(color.t, color.r, color.g, color.b);
		my_mlx_pixel_put(img, position[0], position[1] + y, color.trgb);
		y++;
	}
}

// ct is ct[0], x_y es ct[1], por is ct[2], pos[0] is ct[3], pos[1] is ct[4]
void mega_wall_render(t_global *vars, t_image *img)
{
	int ct[5];
	t_vect intersect;
	
	ft_bzero(ct, 5);
	while (ct[0] < SIZE_X)
	{
		intersect = calc_ray_intersect(vars, ct[0], &ct[1]);
		if (dist_vec(intersect, set_vect(-1,-1)) != 0)
		{
			ct[3] = ct[0];
			ct[4] = SIZE_Y / 2 - 500 / (dist_vec(vars->char_pos, 
				intersect) + 0.1);
			if (ct[1] == 0)
				ct[2] = (int)(50 * fmodf(intersect.x,1.0f));
			else if (ct[1] == 1)
				ct[2] = (int)(50 * fmodf(intersect.y,1.0f));
			if (ct[1] != -1)
				render_wall_col_setup(vars, ct, img, intersect);
		}
		ct[0]++;
	}
}
