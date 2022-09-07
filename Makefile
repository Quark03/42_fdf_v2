NAME = fdf

SRCS =  ./src/gnl.c \
		./src/keys.c \
		./src/lines.c \
		./src/main.c \
		./src/mouse.c \
		./src/parse.c \
		./src/plot.c \
		./src/render.c \
		./src/utils.c \

OBJS = $(SRCS:.c=.o)

MLX = ./mlx/libmlx_Linux.a

LIBFT = ./libft/libft.a

COMPILE = gcc -g -Wall -Wextra -Werror -O3

REMOVE = rm -f

all:	$(NAME)

.c.o:	
	$(COMPILE) -c $< -o $@

$(NAME):	$(LIBFT) $(OBJS)
	$(COMPILE) $(OBJS) $(MLX) $(LIBFT) -lXext -lX11 -lm -lz -o $(NAME)
	

$(LIBFT):
	$(MAKE) -sC ./libft

clean:
	$(REMOVE) $(OBJS)

fclean: clean
	$(REMOVE) $(LIBFT)
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re