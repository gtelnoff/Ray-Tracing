#include "../../../global.h"

double set_diameter(char *str_diameter)
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