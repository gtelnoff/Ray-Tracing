#ifndef     SCENE_H
# define    SCENE_H

#include "scene_elements/ambient_light.h"
#include "scene_elements/camera.h"
#include "scene_elements/cylinder.h"
#include "scene_elements/light.h"
#include "scene_elements/plane.h"
#include "scene_elements/sphere.h"


// Scene struct contain all resources of the scene_file.rt
typedef struct s_scene
{
    t_camera        *camera;
    t_ambient_light *ambients_lights;
    t_light         *lights;
    t_sphere        *spheres;
    t_cylinder      *cylinders;
    t_plane         *palnes;
}   t_scene;

t_scene *scene_parser(char  *scene_path);

#endif