#include "../../../global.h"

bool is_in_range(double nbr, double min, double max)
{
  if (nbr < min || nbr > max)
    return false;

  return true;
}