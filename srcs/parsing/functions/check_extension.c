#include  "../../global.h"

/**
 * @brief Check the extension of file_name he must be in .rt
 * 
 * @param file_name The scene file name containing scene configurations.
 * 
 * @return SUCCESS if extension == .rt | BAD_FILE error
*/
int check_extension(char  *file_name)
{
  int file_path_size;
  int is_good_extension;

  file_path_size = strlen(file_name);
  if (file_path_size < MIN_FILE_PATH_SIZE)
  {
    fprintf(stderr, ERROR_FILE_PATH_SIZE);
    return FILE_ERROR;
  }
  
  file_name += (file_path_size - 3);
  is_good_extension = strncmp(file_name, ".rt", file_path_size - 3);
  if (is_good_extension != 0)
  {
    fprintf(stderr, ERROR_FILE_PATH_EXTENSION);
    return FILE_ERROR;
  }

  return SUCCESS;
}
