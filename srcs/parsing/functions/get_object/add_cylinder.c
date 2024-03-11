#include "../../../global.h"

# define COORDINATES_MALLOC_SIZE 4
# define COORDINATES_NUMBER 3

static t_cylinder  *create_cylinder_struct(char **split_line);
float                *get_coordinates(char *str);
static void initialize_cylinder(t_cylinder  *cylinder);

int add_cylinder(t_scene *scene, char **split_line)
{
  t_cylinder  *new_cylinder;
  t_cylinder  *last_cylinder;

  new_cylinder = create_cylinder_struct(split_line);
  if (new_cylinder == NULL)
    return FAILURE;
  if (scene->cylinders == NULL)
  {
    scene->cylinders = new_cylinder;
    return SUCCESS;
  }

  last_cylinder = scene->cylinders;
  while (last_cylinder->next != NULL)
    last_cylinder = last_cylinder->next;
  last_cylinder->next = new_cylinder;

  return SUCCESS;
}

static t_cylinder  *create_cylinder_struct(char **split_line)
{
  t_cylinder  *cylinder;
  char       *coordinates;

  cylinder = malloc(sizeof(t_cylinder) * 1);
  if (cylinder == NULL)
    return NULL;
  initialize_cylinder(cylinder);
  coordinates = split_line[1];
  printf("%s\n", coordinates);
  cylinder->coordinates = get_coordinates(coordinates);
  if (cylinder->coordinates == NULL)
  {
    free(cylinder);
    return NULL;
  }
  cylinder->next = NULL;

  return cylinder;
}

static void initialize_cylinder(t_cylinder  *cylinder)
{
  cylinder->color = NULL;
  cylinder->coordinates = NULL;
  cylinder->diameter = NULL;
  cylinder->height = NULL;
  cylinder->next = NULL;
  cylinder->vector = NULL;
}

// ajouter le check si il le chiffre est plus grand qu'un double

float *get_coordinates(char *str)
{
  char  **split_coordinates;
  float   *coordinates;
  int    index;

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