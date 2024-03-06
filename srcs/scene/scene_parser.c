#include "../global.h"
#include "scene.h"

int      check_extension(char  *file_name);
t_scene *get_scene_config(char *file_path);
void  print_all(t_scene *scene_config);

/** 
 * @brief This function is the main scene parser. 
 *        He call all sub parsing functions.
 * 
 * @param file_name The file name containing scene configurations.
 * 
 * @return t_scene with scene configurations 
 *         or NULL if we encounter a parser error.
 */
t_scene *scene_parser(char  *file_name)
{
    t_scene *scene_config;
    
    if(check_extension(file_name) == FILE_ERROR)
      return (NULL);
    scene_config = get_scene_config(file_name);
    if (scene_config == NULL)
        return (NULL);
    print_all(scene_config);
    return (scene_config);
}

void  print_all(t_scene *scene_config)
{
  t_cylinder *first_cylinder;

  first_cylinder = scene_config->cylinders;
  if (first_cylinder == NULL)
    return ;
  
  while (first_cylinder->next != NULL)
  {
   printf("x: %f, y: %f, z:%f\n", first_cylinder->coordinates[0], first_cylinder->coordinates[1], first_cylinder->coordinates[2]);

    first_cylinder = first_cylinder->next;
  }
   printf("x: %f, y: %f, z:%f\n", first_cylinder->coordinates[0], first_cylinder->coordinates[1], first_cylinder->coordinates[2]);

  return ;
}
