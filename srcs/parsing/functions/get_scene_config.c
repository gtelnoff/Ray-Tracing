#include  "../../global.h"

static void   initialize_scene_struct(t_scene *scene);
static int    try_open_file(char *file_path);
static char  *get_first_line(char *file_path, int fd);
static int   add_object(t_scene *scene, char *line);

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
    return NULL;

  while (line != NULL)
  {
    add_object(scene, line);
    line = get_next_line(fd);
  }

  return scene;
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
  if (line == NULL)
  {
    fprintf(stderr, "%s%s%s", ERROR_HEADER, file_path, ERROR_EMPTY_FILE);
    return NULL;
  }

  return line;
}

static int  add_object(t_scene *scene, char *line)
{
  char  *object_id;

  line = ft_strtrim_free(line, WHITE_SPACE);
  object_id = get_next_word(&line, ' ');

  if (strcmp(object_id, "cy") == 0)
  {
    add_cylinder(scene, line);
    return SUCCESS;
  }

  return SUCCESS;
}

