NAME = cub3D
NAME_DEBUG = cub_debug

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
	$(SRCS_DIR)/vector_math/rotation.c $(SRCS_DIR)/game/game_loop.c 


OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -g3 -fsanitize=address#-Wall -Wextra -g3 # #-Werror
#CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

MLX = $(MLX_DIR)/libmlx.a

all: make_libft make_mlx $(NAME)

make_libft:
	make all -C $(LIBFT_DIR)

make_mlx:
	make all -C $(MLX_DIR)

debug: make_libft make_mlx $(NAME_DEBUG)

VS_debug: make_libft make_mlx $(NAME_DEBUG)

$(NAME_DEBUG): $(LIBFT_DIR)/libft.a $(SRCS) $(MLX)
	$(CC) $(CFLAGS) $(SRCS) -L$(MLX_DIR) -lmlx $(MLX_FLAGS) $(LIBFT_DIR)/libft.a -o $@

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
	rm -f $(NAME_DEBUG)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re debug VS_debug
