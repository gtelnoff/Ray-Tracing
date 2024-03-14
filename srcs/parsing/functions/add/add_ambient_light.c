#include "../../../global.h"

static t_ambient_light  *create_ambient_light_struct(char **split_line);
static double            set_lighting_ratio(char *str);
int                     *set_rgb_colors(char *str_rgb);
void                     free_ambient_light(t_ambient_light *ambient_light);
bool is_in_range(double nbr, double min, double max);

int add_ambient_light (t_scene *scene, char **split_line)
{
  t_ambient_light *ambient_light;

  if (scene->ambient_light != NULL)
    return FAILURE;

  ambient_light = create_ambient_light_struct(split_line);
  if (ambient_light == NULL)
    return FAILURE;
  
  scene->ambient_light = ambient_light;

  return SUCCESS;
}

static t_ambient_light  *create_ambient_light_struct(char **split_line)
{
  t_ambient_light *ambient_light;

  ambient_light = malloc(sizeof(t_ambient_light));
  if (ambient_light == NULL)
    return NULL;

  ambient_light->ratio = set_lighting_ratio(split_line[1]);
  if (ambient_light->ratio == -1)
  {
    printf("add_ambient_light => set_lighting_ratio fail\n");
    free_ambient_light(ambient_light);
    return NULL;
  }

  ambient_light->color = set_rgb_colors(split_line[2]);
  if (ambient_light->ratio == -1)
  {
    printf("add_ambient_light => set_rgb_colors fail\n");
    free_ambient_light(ambient_light);
    return NULL;
  }

  return ambient_light;
}

static double set_lighting_ratio(char *str)
{
  double lighting_ratio;

  if (!is_number(str))
  {
    // Write_error_not_number(); 
    return -1;
  }
  
  lighting_ratio = strtod(str, NULL);
  if (!is_in_range(lighting_ratio, 0, 1))
  {
    // Write_error_bad_range(); 
    return -1;
  }

  return lighting_ratio;
}