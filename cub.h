/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:59:17 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/14 20:53:25 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

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
# define FOV 3.141592653589793238/4
# define STEP_S 0.02

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_keys {
	int k_a;
	int k_w;
	int k_s;
	int k_d;
	int k_l;
	int k_r;
	int	k_esc;
	int	k_space;
} t_keys;

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
}			t_image;

typedef struct s_vector{
	float x;
	float y;
} t_vect;

typedef struct s_global{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_rows;
	int		map_columns;
	int		floor_color[3];
	int		ceiling_color[3];
	t_image	*NO_texture;
	t_image	*SO_texture;
	t_image	*WE_texture;
	t_image	*EA_texture;
	t_vect	char_pos;
	t_vect	char_facing;
	int long	mouse_pos;
	t_keys	*keys;
}				t_global;

typedef struct s_color {
	int	t;
	int	r;
	int	g;
	int	b;
	int	trgb;
} t_color;

typedef struct s_wall_rend{
	int 	column;
	int 	size;
	int 	position[2];
	t_image *n_wall;
} t_wall_rend;



/*math*/
float dot_prod(t_vect v1, t_vect v2);
float dist_vec(t_vect v1, t_vect v2);
float size_vect(t_vect v);
t_vect rotate_vector(t_vect vec, float rad);
t_vect norm_vect(t_vect v1);
t_vect nearest_point(t_vect point, t_vect origin, t_vect director);
t_vect set_vect(float x, float y);
t_vect inter_lines(t_vect orig1, t_vect dir1, t_vect orig2, t_vect dir2);
t_vect neg_v(t_vect vec);
t_vect add_v(t_vect v1, t_vect v2);
t_vect sub_v(t_vect v1, t_vect v2);
t_vect f_x_v(float f, t_vect v);




/* parser */
int		check_args(int argc, char *file);
int		check_map(char *file);
void	get_map(t_global *vars, char *file);
int		check_borders(char **matrix);

/* start map */
int		start_map(t_global *vars, char *argv);
void	get_positions(t_global *vars);

/* key hooks */
int		initialize_key_hooks(t_global *vars);

/* mlx utils */
int		close_window(t_global *vars);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

/* background */
void	background(t_global *vars);

/* minimap */
int		put_minimap(t_global *vars);

/* move player */
void	move_player(int move_to, t_global *vars);

/* move view */
void move_view(int view_to, t_global *vars);

/* render walls */
//void    render_wall_col(t_global *vars, t_wall_rend *p);
void    render_wall_col(t_global *vars, int column, int size, int *position);
void render_wall(t_global *vars,t_vect cor1, t_vect cor2, t_image *n_wall);


#endif