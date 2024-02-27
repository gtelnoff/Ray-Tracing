#include "../global.h"
#include "scene.h"

/** 
 * @brief This function is the main scene parser. 
 *        He call all sub parsing functions.
 * 
 * @param scene_path The scene path containing scene configurations.
 * 
 * @return t_scene with scene configurations 
 *         or NULL if we encounter a parser error.
 */
t_scene *scene_parser(char  *scene_path)
{
    t_scene *scene_config;
    char    **file;
    
    file = get_file(scene_path);
    if (file == NULL)
        return (NULL);

    return (scene_config);
}