#include "../../../global.h"

# define COORDINATES_MALLOC_SIZE 3
# define COORDINATES_NUMBER 3

static t_sphere   *create_sphere_struct(char **split_line);
static float        *set_coordinates(char *str);
static void          initialize_sphere(t_sphere *sphere);

int add_sphere(t_scene *scene, char **split_line)
{
  t_sphere  *new_sphere;
  t_sphere  *last_sphere;

  if (split_line)

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
    free(sphere);
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

static float *set_coordinates(char *str)
{
  char   **split_coordinates;
  float   *coordinates;
  int      index;

  index = 0;
  split_coordinates = ft_split(str, ',');

  coordinates = malloc(sizeof(int) * COORDINATES_MALLOC_SIZE);
  if (coordinates == NULL)
    return NULL; 

  while (index < COORDINATES_NUMBER)
  {
    if (!is_number(split_coordinates[index]))
    {
      free(coordinates);
      free_2d_array(split_coordinates);
      return NULL;
    }
    coordinates[index] = atof(split_coordinates[index]);
    index++;
  }

  free_2d_array(split_coordinates);
  
  return coordinates;
}