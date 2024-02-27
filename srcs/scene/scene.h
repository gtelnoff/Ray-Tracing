#ifndef     SCENE_H
# define    SCENE_H

#include "scene_elements/ambient_light.h"
#include "scene_elements/camera.h"
#include "scene_elements/cylinder.h"
#include "scene_elements/light.h"
#include "scene_elements/plane.h"
#include "scene_elements/sphere.h"
#include "../global.h"

# define BAD_FILE_PATH 0
# define MIN_FILE_PATH_SIZE 4

# define ERROR_FILE_PATH_SIZE "[ERROR] The file path is too short.\n"

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

t_scene  *scene_parser(char  *scene_path);
char    **get_file(char *path_file);

#endif