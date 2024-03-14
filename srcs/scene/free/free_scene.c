#include "../scene.h"

void  free_all_spheres(t_sphere *spheres);
void  free_camera(t_camera *camera);
void  free_ambient_light(t_ambient_light *ambient_light);

void  free_scene(t_scene *scene)
{
  if (scene == NULL)
    return ;

  free_all_spheres(scene->spheres);
  free_camera(scene->camera);
  free_ambient_light(scene->ambient_light);
  free(scene);

  return ;
}
