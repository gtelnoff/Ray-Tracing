SRCS	= srcs/main.c

OBJS	= $(SRCS:.c=.o)
NAME 	= rayTracing
CC	= clang -g -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -o $(NAME) -lreadline
		echo "It's good !"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
