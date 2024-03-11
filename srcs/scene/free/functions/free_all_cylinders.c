#include  "../../scene.h"

static void  free_cylinder(t_cylinder *cylinder);

void  free_all_cylinders(t_cylinder *cylinder)
{
  t_cylinder *prev_cylinder;

  if (cylinder == NULL)
    return ;

  while (cylinder->next != NULL)
  {
    free_cylinder(cylinder);
    prev_cylinder = cylinder;
    cylinder = cylinder->next;
    free(prev_cylinder);
  }
  free_cylinder(cylinder);
  free(cylinder);
  
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