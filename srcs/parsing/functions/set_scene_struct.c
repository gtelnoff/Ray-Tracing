#include  "../../global.h"

static void   initialize_scene_struct(t_scene *scene);
static char  *get_first_line(char *file_path, int fd);
static int    fill_scene_struct(t_scene *scene, char *line, int fd);
static int    add_object(t_scene *scene, char *line);
static void   free_file(char *line, int fd);

# define WHITE_SPACE " \n\t\r\v\f"

t_scene *set_scene_struct(char *file_path, int fd)
{
  t_scene *scene;
  char    *line;

  scene = malloc(sizeof(t_scene));
  if (scene == NULL)
    return NULL;

  initialize_scene_struct(scene);

  line = get_first_line(file_path, fd);
  if (line == NULL)
  {
    free_scene(scene);
    return NULL;
  }

  if (fill_scene_struct(scene, line, fd) == FAILURE)
    return NULL;
    
  return scene;
}

static void  initialize_scene_struct(t_scene *scene)
{
  scene->ambients_lights = NULL;
  scene->camera = NULL;
  scene->spheres = NULL; 
  scene->lights = NULL;
  scene->planes = NULL;
  scene->cylinder = NULL;
}

static char  *get_first_line(char *file_path, int fd)
{
  char  *line;

  line = get_next_line(fd);
  if (line == NULL)
  {
    //write_error_empty_file(file_path);
    fprintf(stderr, "%s%s%s", ERROR_HEADER, file_path, ERROR_EMPTY_FILE);
    return NULL;
  }

  return line;
}

static int fill_scene_struct(t_scene *scene, char *line, int fd)
{
  while (line != NULL)
  {
    if (add_object(scene, line) == FAILURE)
    {
      free_scene(scene);
      free_file(line, fd);
      return FAILURE;
    }
    free(line);
    line = get_next_line(fd);
  }

  return SUCCESS;
}

static int  add_object(t_scene *scene, char *line)
{
  char  **split_line;
  int     return_value;

  split_line = ft_split(line, ' ');
  if (split_line[0] == NULL)
  {
    free_2d_array(split_line);
    return FAILURE;
  }

  if (strcmp(split_line[0], "sp") == 0)
    return_value = add_sphere(scene, split_line);
  else
    return_value = FAILURE;

  free_2d_array(split_line);
  
  return return_value;
}

static void free_file(char *line, int fd)
{
  while (line != NULL)
  {
    free(line);
    line = get_next_line(fd);
  }
}


