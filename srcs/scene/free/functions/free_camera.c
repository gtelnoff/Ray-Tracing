#include  "../../scene.h"

void  free_camera(t_camera *camera)
{
  if (camera == NULL)
    return ;

  free(camera->coordinates);
  free(camera->orientation);
  free(camera);
} 