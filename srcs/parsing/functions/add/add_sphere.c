#include "../../../global.h"



static t_sphere *create_sphere_struct(char **split_line);
double          *set_coordinates(char *str);
static void      initialize_sphere(t_sphere *sphere);
double           set_diameter(char *diameter);
void             free_all_spheres(t_sphere *sphere);
int             *set_rgb_colors(char *str_rgb);

int add_sphere(t_scene *scene, char **split_line)
{
  t_sphere  *new_sphere;
  t_sphere  *last_sphere;

  if (split_line[0] == NULL)
    return FAILURE;

  new_sphere = create_sphere_struct(split_line);
  if (new_sphere == NULL)
    return FAILURE;

  if (scene->spheres == NULL)
  {
    scene->spheres = new_sphere;
    return SUCCESS;
  }

  last_sphere = scene->spheres;
  while (last_sphere->next != NULL)
    last_sphere = last_sphere->next;
  last_sphere->next = new_sphere;

  return SUCCESS;
}

// Faire un check si {split_line} a bien 4 elements
static t_sphere  *create_sphere_struct(char **split_line)
{
  t_sphere  *sphere;

  sphere = malloc(sizeof(t_sphere) * 1);
  if (sphere == NULL)
    return NULL;

  initialize_sphere(sphere);

  sphere->coordinates = set_coordinates(split_line[1]);
  if (sphere->coordinates == NULL)
  {
    printf("set_coordinates fail\n");
    free_all_spheres(sphere);
    return NULL;
  }

  sphere->diameter = set_diameter(split_line[2]);
  if (sphere->diameter == -1)
  {
    printf("set_diameter fail\n");
    free_all_spheres(sphere);
    return NULL;
  }
  
  sphere->color = set_rgb_colors(split_line[3]);
  if (sphere->color == NULL)
  {
    printf("set_rgb_colors fail\n");
    free_all_spheres(sphere);
    return NULL;
  }

  sphere->next = NULL;

  return sphere;
}

static void initialize_sphere(t_sphere *sphere)
{
  sphere->coordinates = NULL;
  sphere->color = NULL;
  sphere->diameter = 0;
  sphere->next = NULL;
}

// ajouter le check si il le chiffre est plus grand qu'un double
