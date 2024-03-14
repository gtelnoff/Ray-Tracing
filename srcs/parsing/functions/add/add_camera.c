#include "../../../global.h"

static void initialize_camera(t_camera *camera);
double     *set_coordinates(char *str);
static t_camera  *create_camera_struct(char **split_line);
void  free_camera(t_camera *camera);
double  *set_orientation(char *str);
double set_FOV(char *str_FOV);

int add_camera (t_scene *scene, char **split_line)
{
  t_camera *camera;

  if (scene->camera != NULL || split_line[0] == NULL)
    return FAILURE;

  camera = create_camera_struct(split_line);
  if (camera == NULL) 
    return FAILURE;

  scene->camera = camera;

  return SUCCESS;
}

static t_camera  *create_camera_struct(char **split_line)
{
  t_camera *camera;

  camera = malloc(sizeof(t_camera));
  if (camera == NULL)
    return NULL;

  initialize_camera(camera);

  camera->coordinates = set_coordinates(split_line[1]);
  if (camera->coordinates == NULL)
  {
    printf("create_camera_struct => set_coordinates fail\n");
    free_camera(camera);
    free(camera);
    return NULL;
  }

  camera->orientation = set_orientation(split_line[2]);
  if (camera->orientation == NULL)
  {
    printf("create_camera_struct => set_orientation fail\n");
    free_camera(camera);
    free(camera);
    return NULL;
  }

  camera->FOV = set_FOV(split_line[3]);
  if (camera->FOV == -1)
  {
    printf("create_camera_struct => set_FOV fail\n");
    free_camera(camera);
    free(camera);
    return NULL;
  }

  return camera; 
}

static void initialize_camera(t_camera *camera)
{
  camera->coordinates = NULL;
  camera->orientation = NULL;
}