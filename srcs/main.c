#include "global.h"
#include "scene/scene.h"
#include "utils/utils.h"

static bool has_arg_count(int argv);
t_scene *scene_parser(char  *file_name);
void     free_scene(t_scene *scene);

int main(int argc, char** argv)
{
    t_scene *scene;

    if (!has_arg_count(argc))
        return FAILURE;

    scene = scene_parser(argv[SCENE_PATH_INDEX]);
    if (scene == NULL)
    {
        free_scene(scene);
        printf("FAILURE !\n");
        return FAILURE;
    }
    free_scene(scene);
    printf("SUCCESS !\n");
    return SUCCESS;
}

static bool has_arg_count(int argv)
{
    if (argv != REQUIRED_ARG_COUNT)
    {
        print_error(NO_ARG_COUNT);
        return false;
    }
    return true;
}