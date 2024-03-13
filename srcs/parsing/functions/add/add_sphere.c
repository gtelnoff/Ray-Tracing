#include "../../../global.h"

# define COORDINATES_MALLOC_SIZE 3
# define COORDINATES_NUMBER 3
# define SET_DIAMETER_FAIL -1

static t_sphere *create_sphere_struct(char **split_line);
static double   *set_coordinates(char *str);
static void      initialize_sphere(t_sphere *sphere);
static double    set_diameter(char *diameter);
void  free_all_spheres(t_sphere *sphere);
int *set_rgb_colors(char *str_rgb);

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

static double *set_coordinates(char *str)
{
  char   **split_coordinates;
  double  *coordinates;
  int      index;

  index = 0;
  split_coordinates = ft_split(str, ',');
  if (strlen_2d_array(split_coordinates) != COORDINATES_NUMBER)
  {
    free_2d_array(split_coordinates);
    return NULL;
  }

  coordinates = malloc(sizeof(double) * COORDINATES_MALLOC_SIZE + 1);
  if (coordinates == NULL)
    return NULL; 

  while (index < COORDINATES_NUMBER)
  {
    if (!is_number(split_coordinates[index]))
    {
      // Write_error_not_number(str, split_coordinates[index]); 
      free(coordinates);
      free_2d_array(split_coordinates);
      return NULL;
    }
    coordinates[index] = strtod(split_coordinates[index], NULL);
    index++;
  }

  free_2d_array(split_coordinates);
  
  return coordinates;
}

static double set_diameter(char *str_diameter)
{
  double diameter;

  if (!is_number(str_diameter))
  {
    // Write_error_not_number(str, split_coordinates[index]); 
    return -1;
  }
  
  diameter = strtod(str_diameter, NULL);

  return diameter;
}