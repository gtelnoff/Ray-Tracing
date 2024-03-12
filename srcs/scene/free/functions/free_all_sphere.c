#include  "../../scene.h"

static void  free_sphere(t_sphere *sphere);

void  free_all_spheres(t_sphere *sphere)
{
  t_sphere *prev_sphere;

  if (sphere == NULL)
    return ;

  while (sphere->next != NULL)
  {
    free_sphere(sphere);
    prev_sphere = sphere;
    sphere = sphere->next;
    free(prev_sphere);
  }
  free_sphere(sphere);
  free(sphere);
  
  return ;
}

static void  free_sphere(t_sphere *sphere)
{
  free(sphere->coordinates);
  free(sphere->color);

  return ;
}