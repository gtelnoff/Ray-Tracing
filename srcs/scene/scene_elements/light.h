#ifndef     LIGHT_H
# define    LIGHT_H

// L -40.0,50.0,0.0 0.6 10,0,255
typedef struct s_light
{
    // x,y,z coordinates of the light point.
    float   *coordinates;

    // The light brightness ratio in range [0.0,1.0].
    float   brightness;

    // R,G,B light color in range [0-255].
    int*    color;
}	t_light;

#endif