NAME = so_long

LIBFT = ./libft

LIBFT_LIB = libft.a

SRCS = main.c \
	errors.c \
	initialize_map.c \
	checks.c \

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
INCS	= ./
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx_linux -O3 -c $< -o $@


$(NAME): $(OBJS)
	make re -C $(LIBFT)/
	make all -C ./get_next_line/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	cp ./get_next_line/get_next_line.a $(NAME)
	gcc $(OBJS) $(MLXFLAGS) $(NAME) $(SRCS) $(NAME)



all: $(NAME)
    
fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o