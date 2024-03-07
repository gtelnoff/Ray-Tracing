#ifndef     ERROR_H
# define    ERROR_H

#include <string.h>
#include <unistd.h>

# define DEFAULT_ERROR_MSG "[ERROR] An error occurred.\n"
# define NO_ARG_COUNT "[ERROR] Bad argument, use: ./path_tracer \
                       [scene_path].rt\n"

void  print_error(char *error_msg);

#endif