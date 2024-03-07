#ifndef     CYLINDER_H
# define    CYLINDER_H

// Exemple: cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
typedef struct s_cylinder
{
    // x,y,z coordinates of the center of the cylinder.
    float   *coordinates;

    // 3d normalized vector of axis of cylinder. In range [-1,1],
    // for each x,y,z axis.
    float   *vector;

    // The cylinder diameter.
    float   *diameter;

    // The cylinder height.
    float   *height;

    // R,G,B cylinder colors in range [0,255].
    int     *color;

    struct s_cylinder* next;
}	t_cylinder;

#endif