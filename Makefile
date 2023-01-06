NAME = so_long


LIBFT = ./libft

LIBFT_LIB = libft.a

SRCS = ./source/main.c \
	./source/errors.c \
	./source/errors2.c \
	./source/initialize_map.c \
	./source/checks_structure.c \
	./source/check_elements.c \
	./source/rendering.c \
	./source/render_elements.c

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
CC		= gcc -g
FLAGS	= -Wall -Wextra -Werror
INCS	= ./

#MACOS INCLUDES
MLXFLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


macos: $(OBJS)
	make re -C $(LIBFT)/
	$(CC) $(MLXFLAGS) $(LIBFT)/$(LIBFT_LIB) $(SRCS) -o $(NAME)

linux: $(OBJS)
	make re -C $(LIBFT)/
	$(CC) $(OBJS) $(LIBFT)/$(LIBFT_LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


all: macos

fclean: clean
	$(RM) macos linux

clean:
	$(RM) $(OBJS)
	$(RM) so_long

re: fclean all

.PHONY: all linux macos clean fclean re .c.o