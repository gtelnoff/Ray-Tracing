#include  "../../global.h"

int try_open_file(char *file_path)
{
  int fd;

  fd = open(file_path, 0);
  if (fd == -1)
  {
    // write_error_open_failed();
    fprintf(stderr,"%s%s%s" , ERROR_HEADER, ERROR_OPEN_FAILED, file_path);
    return -1;
  }

  return fd;
}