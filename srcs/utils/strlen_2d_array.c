#include "utils.h"

int	strlen_2d_array(char **array)
{
	int	index;

  if (array == NULL)
    return -1;

	index = 0;
	while (array[index] != NULL)
		index++;
	
  return index;
}
