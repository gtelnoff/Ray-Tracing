#include "../../../global.h"

# define COORDINATES_MALLOC_SIZE 3
# define COORDINATES_COUNT 3

bool is_in_range(double nbr, double min, double max);

double *set_coordinates(char *str)
{
  char   **split_coordinates;
  double  *coordinates;
  int      index;

  index = 0;
  split_coordinates = ft_split(str, ',');
  if (strlen_2d_array(split_coordinates) != COORDINATES_COUNT)
  {
    free_2d_array(split_coordinates);
    return NULL;
  }

  coordinates = malloc(sizeof(double) * COORDINATES_MALLOC_SIZE + 1);
  if (coordinates == NULL)
    return NULL; 

  while (index < COORDINATES_COUNT)
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