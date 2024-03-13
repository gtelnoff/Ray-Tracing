#include  "../../global.h"

# define ERROR_FILE_PATH_SIZE "[ERROR] The file path is too short.\n"
# define ERROR_NOT_RT_EXTENSION "[ERROR] This is not a .rt file." \
                                  "Use test.rt for exemple.\n"

/**
 * @brief Check the extension of file_path he must be in .rt.
 * 
 * @param file_path The scene file path containing scene configurations.
 * 
 * @return true if extension == .rt | false.
*/
bool is_rt_extension(char  *file_path)
{
  int file_path_size;

  file_path_size = strlen(file_path);
  if (file_path_size < MIN_FILE_PATH_SIZE)
  {
    //write_error_file_path_size();
    write(2, ERROR_FILE_PATH_SIZE, strlen(ERROR_FILE_PATH_SIZE));
    return false;
  }
  
  file_path += (file_path_size - 3);
  if (strncmp(file_path, ".rt", file_path_size - 3) != 0)
  {
    //write_error_not_rt_extension();
    write(2, ERROR_NOT_RT_EXTENSION, strlen(ERROR_NOT_RT_EXTENSION));
    return false;
  }

  return true;
}