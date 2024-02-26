SRCS	= srcs/main.c srcs/scene/scene_parser/scene_parser.c srcs/utils/get_next_word.c

OBJS	= $(SRCS:.c=.o)
NAME 	= rayTracing
CC	= clang -g #-Wall -Werror -Wextra

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
