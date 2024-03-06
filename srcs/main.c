#include "global.h"
#include "scene/scene.h"
#include "utils/utils.h"

t_scene *scene_parser(char  *file_name);

int main(int argc, char** argv)
{
    t_scene *scene_config;

    if (argc != 2)
    {
        fprintf(stderr, BAD_ARGUMENT);
        return (FAILURE);
    }
    scene_config = scene_parser(argv[SCENE_NAME_INDEX]);
    if (scene_config == NULL)
        return (FAILURE);

    printf("success\n");
    return (SUCCESS);
}