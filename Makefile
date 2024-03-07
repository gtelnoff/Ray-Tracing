SRCS	= srcs/main.c srcs/parsing/functions/get_scene_config.c srcs/parsing/functions/get_object/get_cylinder.c srcs/parsing/functions/check_extension.c srcs/parsing/parser.c srcs/utils/get_next_word.c srcs/utils/print_2d_array.c srcs/utils/free_2d_array.c srcs/utils/is_number.c srcs/utils/ft_strtrim.c srcs/utils/ft_split.c srcs/utils/gnl/get_next_line_utils.c srcs/utils/gnl/get_next_line.c srcs/utils/ft_substr.c srcs/scene/free/functions/free_all_cylinders.c srcs/scene/free/free_scene.c srcs/error/print_error.c
OBJS	= $(SRCS:.c=.o)
NAME 	= rayTracing
CC	= gcc -g -Wall -Werror -Wextra

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
