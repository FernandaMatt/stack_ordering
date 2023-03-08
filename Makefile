NAME = push_swap

SRCS = push_swap.c push_swap_moves.c push_swap_moves2.c order5.c order.c utils.c utils2.c error.c

OBJS = $(SRCS:.c=.o)

LIBS = libft/libft.a

CC = cc

CFLAGS =  -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o  $(NAME)

$(LIBS): libft/
	make -C libft/ all

clean:
	rm -rf *.o libft/*.o

fclean:
	rm -rf *.o libft/*.o push_swap libft/libft.a

re: fclean all

.PHONY:		all clean fclean re
