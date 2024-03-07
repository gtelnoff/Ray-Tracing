#include  "../../scene.h"

static void  free_cylinder(t_cylinder *cylinder);

void  free_all_cylinders(t_cylinder *cylinder)
{
  if (cylinder == NULL)
    return ;

  while (cylinder->next != NULL)
  {
    free_cylinder(cylinder);
    cylinder = cylinder->next;
  }

  return ;
}

static void  free_cylinder(t_cylinder *cylinder)
{
  free(cylinder->coordinates);
  free(cylinder->vector);
  free(cylinder->diameter);
  free(cylinder->height);
  free(cylinder->color);

  return ;
}