NAME	= get_next_line
SRCS	= get_next_line.c main.c
OBJS	= $(SRCS:.c=.o) libft/libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	= 

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all
