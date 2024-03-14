#ifndef     PLANE_H
# define    PLANE_H

// pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
typedef struct s_plane
{
    // x,y,z coordinates of a point in the plane.
    double   *coordinates;

    // 3d normalized normal vector. In range [-1,1] for each x,y,z axis.
    double   *vector;

    // R,G,B plane color in range [0-255].
    int     *color;

    struct s_plane *next;
}	t_plane;

#endif