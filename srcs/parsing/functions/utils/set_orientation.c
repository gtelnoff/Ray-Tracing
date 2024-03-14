#include "../../../global.h"

# define ORIENTATION_MALLOC_SIZE 3
# define ORIENTATION_COUNT 3

bool is_in_range(double nbr, double min, double max);

/**
 * @brief This function retrieves the orientation of an object.
 * 
 * @param str Contains the object's orientation as a string. 
 *            Example: "1,-8,7"
 * 
 * @return An array of doubles of size 3,
 *         containing the object's orientation in x, y, and z.
 */
double  *set_orientation(char *str)
{
  char  **split_str;
  double *orientation;
  int     index;

  index = 0;
  split_str = ft_split(str, ',');
  if (strlen_2d_array(split_str) != ORIENTATION_COUNT)
  {
    free_2d_array(split_str);
    return NULL;
  }
  
  orientation = malloc(sizeof(double) * ORIENTATION_MALLOC_SIZE);
  if (orientation == NULL)
    return NULL;
  
  while (index < ORIENTATION_COUNT)
  {
    if (!is_number(split_str[index]))
    {
      free_2d_array(split_str);
      free(orientation);
      return NULL;
    }

    orientation[index] = strtod(split_str[index], NULL);
    if (!is_in_range(orientation[index], -1, 1))
    {
      free(orientation);
      free_2d_array(split_str);
      return NULL;
    }

    index++;
  }

  free_2d_array(split_str);

  return orientation;
}