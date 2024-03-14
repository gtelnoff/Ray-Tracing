SRCS	= srcs/main.c srcs/parsing/functions/set_scene_struct.c srcs/parsing/functions/utils/set_fov.c srcs/parsing/functions/utils/set_diameter.c srcs/parsing/functions/utils/is_in_range.c srcs/parsing/functions/utils/set_rgb_colors.c srcs/parsing/functions/utils/set_orientation.c srcs/parsing/functions/utils/set_coordinates.c srcs/parsing/functions/try_open_file.c srcs/parsing/functions/add/add_ambient_light.c srcs/parsing/functions/add/add_sphere.c srcs/parsing/functions/add/add_camera.c srcs/parsing/functions/is_rt_extension.c srcs/parsing/parser.c srcs/utils/get_next_word.c srcs/utils/print_2d_array.c srcs/utils/free_2d_array.c srcs/utils/is_number.c srcs/utils/ft_strtrim.c srcs/utils/ft_split.c srcs/utils/gnl/get_next_line_utils.c srcs/utils/gnl/get_next_line.c srcs/utils/strlen_2d_array.c srcs/utils/ft_substr.c srcs/scene/free/functions/free_ambient_light.c srcs/scene/free/functions/free_all_spheres.c srcs/scene/free/functions/free_camera.c srcs/scene/free/free_scene.c srcs/error/print_error.c
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
