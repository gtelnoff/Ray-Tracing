#include "../scene.h"

int check_extension(char  *file_path);

char  **get_file(char *path_file)
{
  char  **file;

  if (check_extension(path_file) == BAD_FILE_PATH)
    return (NULL);
  return (file);
}

int check_extension(char  *file_path)
{
  int file_path_size;

  file_path_size = strlen(file_path);
  if (file_path_size < MIN_FILE_PATH_SIZE)
  {
    fprintf(stderr, ERROR_FILE_PATH_SIZE);
    return (BAD_FILE_PATH);
  }
  file_path += (file_path_size - 3);
  int test = strncmp(file_path, ".rt", file_path_size - 3);
  printf("%d\n", test);
  return (SUCCESS);
}