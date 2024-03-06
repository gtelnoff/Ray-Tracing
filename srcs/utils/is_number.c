#include  "utils.h"
#include  <ctype.h>

/**
 * @brief This function check if the string str is a number.
 * 
 * @return 1 if {str} is a numbre else 0.
*/
int is_number(char *str)
{
  int index;
  int nb_digit;
  int nb_point;

  index = 0;
  nb_digit = 0;
  nb_point = 0;
  if (str == NULL || str[0] == '\0' || \
    str[0] == '.' || str[strlen(str) - 1] == '.')
    return (0);
  if (str[0] == '-' || str[0] == '+')
    index++;
  while (str[index] != '\0')
  {
    if (isdigit(str[index]))
      nb_digit++;
    else if (str[index] == '.')
      nb_point++;
    else
      return (0);
    index++;
  }
  if (nb_digit == 0 || nb_point > 1)
    return (0);
  return (1);
}