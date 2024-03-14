#include  "error.h"

void  print_error(char *error_msg)
{
  if (error_msg == NULL)
  {
    write(2, DEFAULT_ERROR_MSG, strlen(DEFAULT_ERROR_MSG));
    return ;
  }

  write(2, error_msg, strlen(error_msg));
  return ;
}