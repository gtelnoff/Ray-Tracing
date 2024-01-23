#ifndef PLANE_H
# define PLANE_H

// pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
typedef struct s_plane
{
    // x,y,z coordinates of a point in the plane.
    float*    coordinates;

    // 3d normalized normal vector. In range [-1,1] for each x,y,z axis.
    float*   vector;

    // R,G,B plane color in range [0-255].
    int*    color;
}	t_plane;

#endif