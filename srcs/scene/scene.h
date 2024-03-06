#ifndef     SCENE_H
# define    SCENE_H

#include "scene_elements/ambient_light.h"
#include "scene_elements/camera.h"
#include "scene_elements/cylinder.h"
#include "scene_elements/light.h"
#include "scene_elements/plane.h"
#include "scene_elements/sphere.h"
#include "../global.h"

# define FILE_ERROR 1
# define OPEN_FAILED -1
# define MIN_FILE_PATH_SIZE 4
# define BAD_FILE

# define ERROR_HEADER "[ERROR] "

# define ERROR_FILE_PATH_SIZE "[ERROR] The file path is too short.\n"
# define ERROR_FILE_PATH_EXTENSION "[ERROR] Bad file path. Use test.rt for exemple.\n"
# define ERROR_OPEN_FILE "[ERROR] The program not arrive to open this file. Please check the file name or the permission of it.\n"
# define ERROR_EMPTY_FILE " is an empty file !\n"
# define ERROR_OPEN_FAILED "The program failed to open the file: "
// Scene struct contain all resources of the scene_file.rt
typedef struct s_scene
{
    t_camera        *camera;
    t_ambient_light *ambients_lights;
    t_light         *lights;
    t_sphere        *spheres;
    t_cylinder      *cylinders;
    t_plane         *planes;
}   t_scene;

t_scene  *scene_parser(char  *file_name);
int       add_cylinder(t_scene *scene_config, char *line);

#endif