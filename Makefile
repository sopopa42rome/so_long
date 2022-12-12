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

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx_linux -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)
    
fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o