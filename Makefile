NAME = cub3D

SRCS_DIR = ./src
GNL_DIR = ./gnl

MLX_FLAGS = -framework OpenGL -framework AppKit
LIBFT_DIR = ./libft
MLX_DIR = ./mlx

SRCS = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
	$(SRCS_DIR)/parser/check_args.c $(SRCS_DIR)/parser/check_map.c \
	$(SRCS_DIR)/parser/get_positions.c $(SRCS_DIR)/parser/get_map.c \
	$(SRCS_DIR)/main.c $(SRCS_DIR)/game/start_map.c $(SRCS_DIR)/game/key_hooks.c\
	$(SRCS_DIR)/game/mlx_utils.c $(SRCS_DIR)/game/background.c \
	$(SRCS_DIR)/game/minimap/map.c $(SRCS_DIR)/game/minimap/minimap-utils.c \
	$(SRCS_DIR)/game/render_walls.c $(SRCS_DIR)/game/moves_player.c \
	$(SRCS_DIR)/game/ray_caster.c $(SRCS_DIR)/game/ray_caster2.c\
	$(SRCS_DIR)/vector_math/distances.c $(SRCS_DIR)/vector_math/distances_2.c \
	$(SRCS_DIR)/vector_math/rotation.c $(SRCS_DIR)/game/game_loop.c  \
	$(SRCS_DIR)/game/minimap/minimap-utils2.c $(SRCS_DIR)/parser/get_textures.c \
	$(SRCS_DIR)/parser/check_borders.c $(SRCS_DIR)/parser/check_borders2.c \
	$(SRCS_DIR)/parser/check_map2.c $(SRCS_DIR)/parser/check_colors.c \
	$(SRCS_DIR)/parser/get_map2.c $(SRCS_DIR)/parser/check_borders3.c


OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX = $(MLX_DIR)/libmlx.a

all: make_libft make_mlx $(NAME)

make_libft:
	make all -C $(LIBFT_DIR)

make_mlx:
	make all -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -I$(LIBFT_DIR) -I$(MLX_DIR) $(LIBFT_DIR)/libft.a $(MLX) $(MLX_FLAGS) -o $(NAME)
	
%.o: %.c ./libft/libft.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re 
