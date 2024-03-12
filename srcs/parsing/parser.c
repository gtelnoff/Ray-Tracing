#include "../global.h"

static bool  is_rt_extension(char  *file_path);
static int   try_open_file(char *file_path);
t_scene     *set_scene_struct(char *file_path, int fd);
void         print_all(t_scene *scene); // delete

# define ERROR_FILE_PATH_SIZE "[ERROR] The file path is too short.\n"
# define ERROR_NOT_RT_EXTENSION "[ERROR] This is not a .rt file." \
                                  "Use test.rt for exemple.\n"

/** 
 * @brief This function is the main scene parser. 
 *        He call all sub parsing functions.
 * 
 * @param file_path The file name containing scene configurations.
 * 
 * @return t_scene with scene configurations 
 *         or NULL if we encounter a parser error.
 */
t_scene *scene_parser(char  *file_path)
{
    t_scene *scene;
    int      fd;
    
    if (!is_rt_extension(file_path))
      return NULL;

    fd = try_open_file(file_path);
    if (fd == OPEN_FAILED)
      return NULL;

    scene = set_scene_struct(file_path, fd);
    if (scene == NULL)
        return NULL;

    print_all(scene);

    return scene;
}

/**
 * @brief Check the extension of file_path he must be in .rt.
 * 
 * @param file_path The scene file path containing scene configurations.
 * 
 * @return true if extension == .rt | false.
*/
static bool is_rt_extension(char  *file_path)
{
  int file_path_size;

  file_path_size = strlen(file_path);
  if (file_path_size < MIN_FILE_PATH_SIZE)
  {
    //write_error_file_path_size();
    write(2, ERROR_FILE_PATH_SIZE, strlen(ERROR_FILE_PATH_SIZE));
    return false;
  }
  
  file_path += (file_path_size - 3);
  if (strncmp(file_path, ".rt", file_path_size - 3) != 0)
  {
    //write_error_not_rt_extension();
    write(2, ERROR_NOT_RT_EXTENSION, strlen(ERROR_NOT_RT_EXTENSION));
    return false;
  }

  return true;
}

static int try_open_file(char *file_path)
{
  int fd;

  fd = open(file_path, 0);
  if (fd == -1)
  {
    // write_error_open_failed();
    fprintf(stderr,"%s%s%s" , ERROR_HEADER, file_path, ERROR_OPEN_FAILED);
    return -1;
  }

  return fd;
}
















void  print_all(t_scene *scene)
{
  t_sphere *first_sphere;

  first_sphere = scene->spheres;
  if (first_sphere == NULL)
    return ;
  
  while (first_sphere->next != NULL)
  {
   printf("x: %f, y: %f, z:%f\n", first_sphere->coordinates[0], first_sphere->coordinates[1], first_sphere->coordinates[2]);

    first_sphere = first_sphere->next;
  }
   printf("x: %f, y: %f, z:%f\n", first_sphere->coordinates[0], first_sphere->coordinates[1], first_sphere->coordinates[2]);

  return ;
}
