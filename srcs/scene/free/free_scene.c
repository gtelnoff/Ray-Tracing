#include "../scene.h"

void  free_all_cylinders(t_cylinder *cylinders);

void  free_scene(t_scene *scene)
{
  if (scene == NULL)
    return ;
  if (scene->cylinders != NULL)
    free_all_cylinders(scene->cylinders);
  free(scene);
  return ;
}
