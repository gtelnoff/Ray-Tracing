SRCS	= srcs/main.c srcs/utils/get_next_word.c srcs/utils/print_2d_array.c srcs/utils/free_2d_array.c srcs/utils/is_number.c srcs/utils/ft_strtrim.c srcs/utils/ft_split.c srcs/utils/gnl/get_next_line_utils.c srcs/utils/gnl/get_next_line.c srcs/utils/ft_substr.c srcs/scene/scene_parser_functions/get_scene_config.c srcs/scene/scene_parser_functions/get_object/get_cylinder.c srcs/scene/scene_parser_functions/check_extension.c srcs/scene/scene_parser.c
OBJS	= $(SRCS:.c=.o)
NAME 	= rayTracing
CC	= gcc -g #-Wall -Werror -Wextra

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
