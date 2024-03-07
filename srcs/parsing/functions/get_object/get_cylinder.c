#include "../../../global.h"

# define COORDINATES_MALLOC_SIZE 4
# define COORDINATES_NUMBER 3

static t_cylinder  *create_cylinder_struct(char *line);
float                *get_coordinates(char *str);

int add_cylinder(t_scene *scene, char *line)
{
  t_cylinder  *new_cylinder;
  t_cylinder  *last_cylinder;

  new_cylinder = create_cylinder_struct(line);
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

static t_cylinder  *create_cylinder_struct(char *line)
{
  t_cylinder  *cylinder;
  char       *coordinates;

  cylinder = malloc(sizeof(t_cylinder) * 1);
  if (cylinder == NULL)
    return NULL;
  coordinates = get_next_word(&line, ' ');
  cylinder->coordinates = get_coordinates(coordinates);
  if (cylinder->coordinates == NULL)
  {
    //free
    return NULL;
  }
  cylinder->next = NULL;
  
  return cylinder;
}

// ajouter le check si il le chiffre est plus grand qu'un double
float *get_coordinates(char *str)
{
  char  *next_coordinate;
  float   *coordinates;
  int    index;

  index = 0;
  coordinates = malloc(sizeof(int) * COORDINATES_MALLOC_SIZE);
  if (coordinates == NULL)
    return NULL; 
  while (index < COORDINATES_NUMBER)
  {
    next_coordinate = get_next_word(&str, ',');
    if (next_coordinate == NULL || !is_number(next_coordinate))
    {
      free(coordinates);
      return NULL;
    }
    coordinates[index] = atof(next_coordinate);
    index++;
  }

  return coordinates;
}