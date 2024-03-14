#include "../global.h"

bool         is_rt_extension(char  *file_path);
int          try_open_file(char *file_path);
t_scene     *set_scene_struct(char *file_path, int fd);
void         print_all(t_scene *scene); // delete

/** 
 * @brief This function is the main scene parser. 
 *        He call all sub parsing functions.
 * 
 * @param file_path The file path containing scene configurations.
 *                  All scene are in srcs/scene/config.
 * 
 * @return t_scene with scene configurations 
 *         or NULL if we encounter a parser error.
 */
t_scene *scene_parser(char *file_path)
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

















void  print_all(t_scene *scene)
{
  t_sphere *first_sphere;

  first_sphere = scene->spheres;
  if (first_sphere == NULL)
    return ;
  //printf("CAMERA => coordinate: x: %f, y: %f, z:%f\n", scene->camera->coordinates[0], scene->camera->coordinates[1], scene->camera->coordinates[2]);
  while (first_sphere->next != NULL)
  {
   printf("x: %f, y: %f, z:%f\n", first_sphere->coordinates[0], first_sphere->coordinates[1], first_sphere->coordinates[2]);
  printf("diameter: %f\n", first_sphere->diameter);
   printf("r: %d, g: %d, b:%d\n", first_sphere->color[0], first_sphere->color[1], first_sphere->color[2]);

    first_sphere = first_sphere->next;
  }
   printf("x: %f, y: %f, z:%f\n", first_sphere->coordinates[0], first_sphere->coordinates[1], first_sphere->coordinates[2]);
   printf("diameter: %f\n", first_sphere->diameter);
   printf("r: %d, g: %d, b:%d\n", first_sphere->color[0], first_sphere->color[1], first_sphere->color[2]);

  return ;
}
