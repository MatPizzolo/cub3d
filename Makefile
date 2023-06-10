NAME = cub3D
NAME_DEBUG = cub_debug

SRCS_DIR = ./src
GNL_DIR = ./gnl

SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/key_hooks.c $(SRCS_DIR)/mlx_utils.c $(SRCS_DIR)/background.c  $(SRCS_DIR)/parser/check_args.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

debug: CFLAGS += -D DEBUG=1 
debug: $(NAME_DEBUG) 

VS_debug: CFLAGS += -D DEBUG=1
VS_debug: $(NAME_DEBUG)

$(NAME_DEBUG): libft/libft.a $(SRCS)
	$(CC) $(CFLAGS) -fdiagnostics-color=always -g $(SRCS) -Lmlx -lmlx \
	-framework OpenGL -framework AppKit libft/libft.a -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit \
	-L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c ./libft/libft.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_DEBUG) 
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re debug VS_debug
