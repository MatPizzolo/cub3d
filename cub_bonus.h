/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:03:44 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/22 17:45:09 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# define SIZE_X 1920
# define SIZE_Y 1080
# define PI 3.141592653589793238
# define KH_A 0
# define KH_W 13
# define KH_S 1
# define KH_D 2
# define KH_ESC 53
# define KH_LK 123
# define KH_RK 124
# define KH_SPACE 49
# define FOV 0.392699081
# define SIZEC 300
# define D_TO_SCREEN 4826.24591 // SIZE_X /2 / tanf(FOV/2)
# define W_SIZE 3000

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_keys {
	int	k_a;
	int	k_w;
	int	k_s;
	int	k_d;
	int	k_l;
	int	k_r;
	int	k_esc;
	int	k_space;
}	t_keys;

typedef struct s_image {
	char	*file;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*pixels;
	int		size[2];
	int		pos[2];
	int		width;
	int		height;	
}	t_image;

typedef struct s_vector{
	float	x;
	float	y;
}	t_vect;

typedef struct s_map{
	float	scale;
	float	color;
}	t_map;

typedef struct s_parser{
	int		c_color;
	int		f_color;
	int		no_texture;
	int		so_texture;
	int		we_texture;
	int		ea_texture;
}	t_parser;

typedef struct s_global{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_rows;
	int		map_columns;
	int		floor_color[3];
	int		ceiling_color[3];
	t_image	*no_texture;
	t_image	*so_texture;
	t_image	*we_texture;
	t_image	*ea_texture;
	t_vect	char_pos;
	t_vect	char_facing;
	t_vect	mouse_pos;
	t_keys	*keys;
}	t_global;

typedef struct s_color {
	int	t;
	int	r;
	int	g;
	int	b;
	int	trgb;
}	t_color;

typedef struct s_wall_rend{
	int		column;
	int		size;
	int		position[2];
	t_image	*img_dst;
	t_image	*n_wall;
}	t_wall_rend;

/*math*/
float	dot_prod(t_vect v1, t_vect v2);
float	dist_vec(t_vect v1, t_vect v2);
float	size_vect(t_vect v);
t_vect	rotate_vector(t_vect vec, float rad);
t_vect	norm_vect(t_vect v1);
t_vect	nearest_point(t_vect point, t_vect origin, t_vect director);
t_vect	set_vect(float x, float y);
t_vect	inter_lines(t_vect orig1, t_vect dir1, t_vect orig2, t_vect dir2);
t_vect	neg_v(t_vect vec);
t_vect	add_v(t_vect v1, t_vect v2);
t_vect	sub_v(t_vect v1, t_vect v2);
t_vect	f_x_v(float f, t_vect v);
float	vec_angle(t_vect base, t_vect other);

/* parser */
int		ft_isspace(int c);
int		check_args(int argc, char *file);
int		check_map(char *file);
void	get_map(t_global *vars, char *file);
int		check_borders(char *file);
int		check_borders2(char **matrix, size_t columns, int rows);
int		ft_strichr_sp(const char *s, int c, int len);
int		check_diff_chars(char **matrix);
int		check_for_colors(char *line, t_parser *pars);
void	initialize_pars_struct(t_parser *pars);
int		check_pars_struct(t_parser pars);
int		check_map_before(char *line, t_parser *p);
int		one_player(int fd);
int		check_color(char *line);
int		*where_is_p(char **matrix);
int		check_borders_a(char **matrix, size_t columns, int rows);
char	*get_first_line_map(char *file, int *fd);
int		print_msg_checker_map(char *line);

/* start map */
int		start_map(t_global *vars, char *argv);
void	get_positions(t_global *vars);
void	get_text_colors(int fd, t_global *vars);
void	texture_no(char *line, t_global *vars);
void	texture_so(char *line, t_global *vars);
void	texture_we(char *line, t_global *vars);
void	texture_ea(char *line, t_global *vars);

/* key hooks */
int		initialize_key_hooks(t_global *vars);

/* mlx utils */
int		close_window(t_global *vars);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	ft_free_split(char **split);

/* background */
void	draw_background(t_global *vars, t_image *img);

/* minimap */
int		put_minimap(t_global *vars);
int		put_map(t_global *vars);
void	scale_map(t_global *vars, t_image *m_map, int map_width);
void	draw_line(t_global *vars, t_image *m_map, t_vect vect, t_map map);
void	draw_scaled_pixel(t_image *m_map, int x, int y, t_map map);
void	draw_circle(t_image *m_map, t_vect vect, int radius, t_map map);

/* key hook */
int		game_loop(void *param);
int		key_released(int keycode, t_global *vars);
int		key_press(int keycode, t_global *vars);
int		key_actions(t_global *vars);
void	mouse_move(t_global *vars);

/* move player */
void	move_player(int move_to, t_global *vars);

/* move view */
void	move_view(int view_to, t_global *vars);

/* render walls */
//void    render_wall_col(t_global *vars, int column, int size, int *position, 
//	t_image *img);
void	render_wall_col(t_wall_rend *p);
void	mega_wall_render(t_global *vars, t_image *img);
void	render_wall_col_setup(t_global *vars, int *ct, t_image *img,
			t_vect intersect);
t_vect	calc_ray_intersect(t_global *vars, int hor_pix, int *x_y);
t_image	*texture_selector(t_global *vars, t_vect intersect, int x_y);
int		check_y_quality(t_global *vars, t_vect *posib, int *it);
int		check_x_quality(t_global *vars, t_vect *posib, int *it);

#endif