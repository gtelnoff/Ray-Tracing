#ifndef     SPHERE_H
# define    SPHERE_H

// sp 0.0,0.0,20.6 12.6 10,0,255
typedef struct s_sphere
{
    // x,y,z coordinates of the the sphere center.
    float   *coordinates;

    // The sphere diameter.
    float   diameter;

    // R,G,B sphere color in range [0-255].
    int     *color;
    
    struct t_sphere *next;
}	t_sphere;

#endif