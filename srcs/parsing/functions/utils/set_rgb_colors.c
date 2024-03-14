#include "../../../global.h"

static bool is_rgb_colors(char  **split_rgb);
static bool has_point(char *str);
static bool has_range_color(char *str);

int *set_rgb_colors(char *str_rgb)
{
  char  **split_rgb;
  int *rgb;

  rgb = malloc(sizeof(int) * 3);
  if (rgb == NULL)
    return NULL;
  
  split_rgb = ft_split(str_rgb, ',');
  if (strlen_2d_array(split_rgb) != 3)
  {
    printf("set_rgb_colors -> strlen_2d_array() failed.");
    free(rgb);
    free_2d_array(split_rgb);
    return NULL;
  }

  if (!is_rgb_colors(split_rgb))
  {
    printf("set_rgb_colors -> is_rgb_colors() failed.");
    free_2d_array(split_rgb);
    free(rgb);
    return NULL;
  }

  rgb[0] = atoi(split_rgb[0]);
  rgb[1] = atoi(split_rgb[1]);
  rgb[2] = atoi(split_rgb[2]);
  free_2d_array(split_rgb);

  return rgb;
}

static bool is_rgb_colors(char **split_rgb)
{
  int index;

  index = 0;
  while (index < 3)
  {
    printf("%s\n", split_rgb[index]);
    if (!is_number(split_rgb[index]))
      return false;
    
    if (has_point(split_rgb[index]) || !has_range_color(split_rgb[index]))
      return false;
     printf("%s\n", split_rgb[index]);
    index++;
  }

  return true;
}

static bool has_point(char *str)
{
  int index;

  index = 0;
  while (str[index] != '\0')
  {
    if (str[index] == '.')
      return true;
    index++;
  }

  return false;
}

static bool has_range_color(char *str)
{
  int color;

  if (strlen(str) > 3)
    return false;

  color = atoi(str);
  if (color < 0 || color > 255)
    return false;

  return true;
}