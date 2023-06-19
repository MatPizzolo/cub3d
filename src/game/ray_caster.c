#include "../../cub.h"

void ray_x_intersect(t_global *vars, t_vect *posib)
{
	int	it[2];

	it[0] = (int)floorf(vars->char_pos.x);
	it[1] = -1;
	if (posib[2].x == 0)
		posib[0] = set_vect(-1, -1);
	else
	{
		if (posib[2].x > 0)
		{
			it[1] = 1;
			it[0]++;
		}
		while (it[0] > 0 && it[0] < vars->map_columns)
		{
			posib[0] = inter_lines(vars->char_pos, posib[2], set_vect(it[0], 0),
					set_vect(0, 1));
			if (posib[0].y > 0 && posib[0].y < vars->map_rows && vars->map[
					(int)floorf(posib[0].y)][it[0] + (it[1] - 1) / 2] == '1')
				break ;
			it[0] += it[1];
		}
		if (it[0] == vars->map_columns || it[0] == 0)
			posib[0] = set_vect(-1, -1);
	}
}

// it[0] es it it[1] es dir
void	ray_y_intersect(t_global *vars, t_vect *posib)
{
	int	it[2];

	it[0] = (int)floorf(vars->char_pos.y);
	it[1] = -1;
	if (posib[2].y == 0)
		posib[1] = set_vect(-1, -1);
	else
	{
		if (posib[2].y > 0)
		{
			it[1] = 1;
			it[0]++;
		}
		while (it[0] > 0 && it[0] < vars->map_rows)
		{
			posib[1] = inter_lines(vars->char_pos, vars->char_facing,
					set_vect(0, it[0]), set_vect(1, 0));
			if (posib[1].y > 0 && posib[1].y < vars->map_rows && vars->map[
					it[0] + (it[1] - 1) / 2][(int)floorf(posib[1].x)] == '1')
				break ;
			it[0] += it[1];
		}
		if (it[0] == vars->map_rows || it[0] == 0)
			posib[1] = set_vect(-1, -1);
	}
}

t_vect	choose_best_intersect(t_global *vars, t_vect *posib, int *x_y)
{
	*x_y = 1;
	if (dist_vec(posib[0], set_vect(-1, -1)) == 0 && \
		dist_vec(posib[1], set_vect(-1, -1)) == 0)
	{
		*x_y = -1;
		return (set_vect(-1, -1));
	}
	else if (dist_vec(posib[0], set_vect(-1, -1)) == 0 && \
		dist_vec(posib[1], set_vect(-1, -1)) > 0)
		return (posib[1]);
	else if (dist_vec(posib[0], set_vect(-1, -1)) > 0 && \
		dist_vec(posib[1], set_vect(-1, -1)) == 0)
	{
		*x_y = 0;
		return (posib[0]);
	}
	else if (dist_vec(posib[0], vars->char_pos) > dist_vec(posib[1],
			vars->char_pos))
		return (posib[1]);
	*x_y = 0;
	return (posib[0]);
}

t_vect	calc_ray_intersect(t_global *vars, int hor_pix, int *x_y)
{
	t_vect	posib[3];
	int		it;
	int		dir;
	float	pix_rot;

	if (hor_pix < 960)
		pix_rot = -atan((960 - hor_pix) / D_TO_SCREEN);
	else
		pix_rot = atan((hor_pix - 960) / D_TO_SCREEN);
	posib[2] = rotate_vector(vars->char_facing, pix_rot);
	ray_x_intersect(vars, posib);
	ray_y_intersect(vars, posib);
	return (choose_best_intersect(vars, posib, x_y));
}


t_image *texture_selector(t_global *vars, t_vect intersect, int x_y)
{
	t_image tmp;

	tmp.img = mlx_xpm_file_to_image(vars->mlx, "./assets/wall_SO.xpm", &tmp.width, &tmp.height);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bits_per_pixel, &tmp.line_length, &tmp.endian);
	if (!(x_y == 0 || x_y ==1))
		return (NULL);
	if (x_y == 0 && sub_v(intersect, vars->char_pos).x < 0)
		return (vars->we_texture); 
	if (x_y == 0 && sub_v(intersect, vars->char_pos).x > 0)
		return (vars->ea_texture); 
	if (x_y == 1 && sub_v(intersect, vars->char_pos).y < 0)
		return (vars->no_texture); 
	if (x_y == 1 && sub_v(intersect, vars->char_pos).y > 0)
		return (vars->so_texture); 
	return (NULL);
	
}

void	render_wall_col_setup(t_global *vars, int *ct, t_image *img, 
	t_vect intersect)
{
	t_wall_rend p;

	p.column = ct[2];
	p.img_dst = img;
	p.position[0] = ct[3];
	p.position[1] = ct[4];
	p.size = 1000 / (dist_vec(vars->char_pos, intersect) + 0.1);
	// p.n_wall = texture_selector(vars, intersect, ct[1]);

	t_image tmp;

	tmp.img = mlx_xpm_file_to_image(vars->mlx, "./assets/wall_SO.xpm", &tmp.width, &tmp.height);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bits_per_pixel, &tmp.line_length, &tmp.endian);

	p.n_wall = &tmp;

	render_wall_col(vars, &p);
}