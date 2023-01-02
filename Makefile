NAME = so_long

LIBFT = ./libft

LIBFT_LIB = libft.a

SRCS = ./source/main.c \
	./source/errors.c \
	./source/errors2.c \
	./source/initialize_map.c \
	./source/checks_structure.c \
	./source/check_elements.c \
	./source/rendering.c

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


linux: $(OBJS)
	make re -C $(LIBFT)/
#gcc -c $(MLXFLAGSLINUX) $(SRCS)
#ar rcs ./source/so_long.a $(OBJS)
	$(CC) $(OBJS) $(LIBFT)/$(LIBFT_LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

macos: $(OBJS)
	make re -C $(LIBFT)/
	gcc $(MLXFLAGS) $(LIBFT)/$(LIBFT_LIB) $(SRCS) -o $(NAME)
	rm ./source/*.o

all: macos

fclean: clean
	$(RM) macos linux

clean:
	$(RM) ./source/so_long.a $(OBJS)
	$(RM) $(OBJS)
	
re: fclean all

.PHONY: all linux clean fclean re .c.o