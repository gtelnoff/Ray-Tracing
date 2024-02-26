#ifndef     CAMERA_H
# define    CAMERA_H

// Exemple: C -50.0,0,20 0,0,1 70
typedef struct s_camera
{
    // x,y,z coordinates of the view point.                   
	float   *coordinates;

    // 3d normalized orientation vector. In range [-1,1] for each x,y,z axis.
    float   *orientation;
    
    // Horizontal field of view in degrees in range [0,180].
    int     FOV;

}	t_camera;

#endif