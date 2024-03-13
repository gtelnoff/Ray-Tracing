#ifndef     AMBIENT_LIGHT_H
# define    AMBIENT_LIGHT_H

// Exemple: A 0.2 255,255,255
typedef struct s_ambient_light
{
    // Ambient lighting ratio in range [0.0,1.0].
	double   ratio;

    // R,G,B ambient light color in range [0-255].
    int     *color;
}	t_ambient_light;

#endif