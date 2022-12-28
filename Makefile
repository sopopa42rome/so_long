NAME = so_long

LIBFT = ./libft

LIBFT_LIB = libft.a

SRCS = ./source/main.c \
	./source/errors.c \
	./source/initialize_map.c \
	./source/checks_structure.c \
	./source/check_elements.c \

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
INCS	= ./
#MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLXFLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx_linux -O3 -c $< -o $@


$(NAME): $(OBJS)
	make re -C $(LIBFT)/
	make re -C ./get_next_line/
# cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
# cp ./get_next_line/get_next_line.a $(NAME)
	gcc -g $(MLXFLAGS) $(LIBFT)/$(LIBFT_LIB) ./get_next_line/get_next_line.a $(SRCS) -o $(NAME)
	rm ./source/*.o



all: $(NAME)
    
fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o