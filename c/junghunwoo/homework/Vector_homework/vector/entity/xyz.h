#ifndef __XYZ_H__
#define __XYZ_H__

typedef struct _xyz xyz;

struct _xyz
{
    int x_number;
    int y_number;
    int z_number;
};

#define MIN     -9
#define MAX     9

xyz *init_xyz_object(void);
void random_xyz(xyz *object);
void print_xyz_object(xyz *object);

#endif