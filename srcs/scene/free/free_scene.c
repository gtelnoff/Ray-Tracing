#include "../scene.h"

void  free_all_spheres(t_sphere *spheres);

void  free_scene(t_scene *scene)
{
  if (scene == NULL)
    return ;
  if (scene->spheres != NULL)
    free_all_spheres(scene->spheres);
  free(scene);
  return ;
}
