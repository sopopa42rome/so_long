NAME = so_long


LIBFT = ./libft

LIBFT_LIB = libft.a

SRCS = ./source/main.c \
	./source/errors.c \
	./source/errors2.c \
	./source/errors_3.c \
	./source/initialize_map.c \
	./source/checks_structure.c \
	./source/check_elements.c \
	./source/rendering.c \
	./source/render_elements.c \
	./source/render_elements_2.c \
	./source/movements.c 

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
CC		= gcc
DEBUG_LEAKS	= gcc -g -fsanitize=address
FLAGS	= -Wall -Wextra -Werror
INCS	= ./

#MACOS INCLUDES
MLXFLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: macos

macos: $(OBJS)
	make re -C $(LIBFT)/
	$(DEBUG_LEAKS) $(MLXFLAGS) $(LIBFT)/$(LIBFT_LIB) $(SRCS) -o $(NAME)

linux: $(OBJS)
	make re -C $(LIBFT)/
	$(CC) $(OBJS) $(LIBFT)/$(LIBFT_LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lXrender -lm -lz -o $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all linux macos clean fclean re .c.o