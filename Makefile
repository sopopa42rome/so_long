NAME = so_long

LIBFT = ./libft

LIBFT_LIB = libft.a

SRCS = ./source/main.c \
	./source/errors.c \
	./source/errors2.c \
	./source/initialize_map.c \
	./source/checks_structure.c \
	./source/check_elements.c \

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
INCS	= ./
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#MLXFLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(FLAGS) -Imlx_linux -O3 -c $< -o $@


$(NAME): $(OBJS)
	make re -C $(LIBFT)/
	make re -C ./get_next_line/
	make re -C ./mlx_linux
	gcc -c $(MLXFLAGS) $(SRCS)
	ar rcs ./source/so_long.a $(OBJS)
	gcc ./source/so_long.a ./get_next_line/get_next_line.a $(LIBFT)/$(LIBFT_LIB)
	mv a.out $(NAME)
	rm ../so_long/*.o

all: $(NAME)
    
fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) ./source/so_long.a $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o