#include  "../scene.h"

static void   initialize_scene_struct(t_scene *scene_config);
static int    try_open_file(char *file_path);
static char  *get_first_line(char *file_path, int fd);
static int   get_object(t_scene *scene_config, char *line);

t_scene *get_scene_config(char *file_path)
{
  t_scene  *scene_config;
  char    *line;
  int      fd;

  scene_config = malloc(sizeof(t_scene));
  initialize_scene_struct(scene_config);
  fd = try_open_file(file_path);
  if (fd == OPEN_FAILED)
    return (NULL);
  line = get_first_line(file_path, fd);
  if (line == NULL)
    return (NULL);
  while (line != NULL)
  {
    get_object(scene_config, line);
    line = get_next_line(fd);
  }
  return (scene_config);
}

void  initialize_scene_struct(t_scene *scene_config)
{
  scene_config->ambients_lights = NULL;
  scene_config->camera = NULL;
  scene_config->cylinders = NULL;
  scene_config->lights = NULL;
  scene_config->planes = NULL;
  scene_config->spheres = NULL;
  return ;
}

static int try_open_file(char *file_path)
{
  int fd;

  fd = open(file_path, 0);
  if (fd == -1)
  {
    fprintf(stderr,"%s%s%s" , ERROR_HEADER, file_path, ERROR_OPEN_FAILED);
    return (-1);
  }
  return (fd);
}

static char  *get_first_line(char *file_path, int fd)
{
  char  *line;

  line = get_next_line(fd);
  if (line == NULL)
  {
    fprintf(stderr, "%s%s%s", ERROR_HEADER, file_path, ERROR_EMPTY_FILE);
    return (NULL);
  }
  return (line);
}

static int  get_object(t_scene *scene_config, char *line)
{
  char  *object_id;
  int    return_value;

  line = ft_strtrim_free(line, " \n\t\r\v\f");
  object_id = get_next_word(&line, ' ');

  if (strcmp(object_id, "cy") == 0)
  {
    return_value = add_cylinder(scene_config, line);
    return (SUCCESS);
  }
  return (SUCCESS);
}

