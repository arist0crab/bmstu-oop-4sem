#ifndef __ACTIONS_H__
#define __ACTIONS_H__

#include "status.h"
#include "figure.h"
#include <iostream>
using namespace std;

typedef enum
{
    LOAD_FIGURE,
    DRAW_FIGURE,
    MOVE_FIGURE,
    SCALE_FIGURE,
    ROTATE_FIGURE
} request_type_t;

typedef struct
{
    request_type_t type;
    draw_scene_t scene;
    union
    {
        const char *filename;
        struct { double dx, dy, dz; } move_data;
        struct { double kx, ky, kz; } scale_data;
        struct { double ax, ay, az; } rotate_data;
    };
} request_t;

status_t manage_request(request_t request, figure_t &figure);

#endif