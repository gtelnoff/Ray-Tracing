#include "../../../global.h"

bool is_in_range(double nbr, double min, double max);

double set_FOV(char *str_FOV)
{
  double FOV;

  if (!is_number(str_FOV))
  {
    // Write_error_not_number(); 
    return -1;
  }
  
  FOV = strtod(str_FOV, NULL);
  if (!is_in_range(FOV, 0, 180))
  {
    // Write_error_bad_range(); 
    return -1;
  }

  return FOV;
}