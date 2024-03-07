#ifndef     DEFINE_H
# define    DEFINE_H

#include  <math.h>
#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include "utils/utils.h"
#include "error/error.h"
#include "scene/scene.h"

# define REQUIRED_ARG_COUNT 2
# define SUCCESS 0
# define FAILURE 1
# define SCENE_PATH_INDEX 1

// Error messages
# define BAD_ARGUMENT "[ERROR] Bad argument, use: ./path_tracer \
                       [scene_path].rt\n"
#endif
