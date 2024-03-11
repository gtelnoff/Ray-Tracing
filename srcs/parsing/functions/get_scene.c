#include  "../../global.h"

static void   initialize_scene_struct(t_scene *scene);
static int    try_open_file(char *file_path);
static char  *get_first_line(char *file_path, int fd);
static int   add_object(t_scene *scene, char *line);
static void read_all_file(char *line, int fd);

# define WHITE_SPACE " \n\t\r\v\f"

t_scene *get_scene(char *file_path)
{
  t_scene  *scene;
  char    *line;
  int      fd;

  scene = malloc(sizeof(t_scene));
  if (scene == NULL)
    return NULL;
  initialize_scene_struct(scene);

  fd = try_open_file(file_path);
  if (fd == OPEN_FAILED)
  {
    free_scene(scene);
    return NULL;
  }

  line = get_first_line(file_path, fd);
  if (line == NULL)
  {
    free_scene(scene);
    return NULL;
  }

  while (line != NULL)
  {
    if (add_object(scene, line) == FAILURE)
    {
      free_scene(scene);
      read_all_file(line, fd);
      return NULL;
    }
    printf("lol\n");
    free(line);
    line = get_next_line(fd);
  }
  return scene;
}
static void read_all_file(char *line, int fd)
{
  while (line != NULL)
  {
    free(line);
    line = get_next_line(fd);
  }
}

void  initialize_scene_struct(t_scene *scene)
{
  scene->ambients_lights = NULL;
  scene->camera = NULL;
  scene->cylinders = NULL;
  scene->lights = NULL;
  scene->planes = NULL;
  scene->spheres = NULL;

  return ;
}

static int try_open_file(char *file_path)
{
  int fd;

  fd = open(file_path, 0);
  if (fd == -1)
  {
    fprintf(stderr,"%s%s%s" , ERROR_HEADER, file_path, ERROR_OPEN_FAILED);
    return -1;
  }

  return fd;
}

static char  *get_first_line(char *file_path, int fd)
{
  char  *line;

  line = get_next_line(fd);
  printf("JE FAIS: %s\n", line);
  printf("Adresse mémoire de la variable : %p\n", (void *)line);
  if (line == NULL)
  {
    fprintf(stderr, "%s%s%s", ERROR_HEADER, file_path, ERROR_EMPTY_FILE);
    return NULL;
  }

  return line;
}

static int  add_object(t_scene *scene, char *line)
{
  char  **split_line;
  int   return_value;

  split_line = ft_split(line, ' ');
  if (strcmp(split_line[0], "cy") == 0)
    return_value = add_cylinder(scene, split_line) == FAILURE;
  else
    return_value = FAILURE;
  free_2d_array(split_line);
  
  return return_value;
}

