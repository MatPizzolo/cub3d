NAME = libft.a

LIB = ar rcs
CFLAGS = -Wall -Wextra -Werror
CC				= gcc 
RM				= rm -f


MY_SRC	=	 ft_isalnum.c ft_isprint.c ft_memcmp.c  \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c  \
					ft_memmove.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_strjoin.c  ft_strtrim.c ft_substr.c  ft_itoa.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strichr.c

BONUS_SRC	=   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_striteri.c ft_lstmap.c

MY_OBJS = $(MY_SRC:%.c=%.o)
BONUS_OBJS = $(BONUS_SRC:%.c=%.o)

all:			$(NAME)

$(NAME): $(MY_OBJS) 
			$(LIB) $(NAME) $(MY_OBJS)

bonus:  $(BONUS_OBJS)
			$(LIB) $(NAME)  $(BONUS_OBJS) 

%.o: %.c 
	$(CC) $(CFLAGS) -c $^ -o $@ 

clean:
			$(RM) $(MY_OBJS) $(BONUS_OBJS) 		

fclean:		clean
			$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
