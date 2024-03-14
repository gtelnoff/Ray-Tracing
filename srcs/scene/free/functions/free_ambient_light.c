#include  "../../scene.h"

void  free_ambient_light(t_ambient_light *ambient_light)
{
  if (ambient_light == NULL)
    return ;

  free(ambient_light->color);
  free(ambient_light);
} 