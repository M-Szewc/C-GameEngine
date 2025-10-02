#pragma once

#include "defines.h"

struct game;

typedef struct application_config {
    // Starting window x position, if applicable
    i16 start_pos_x;

    // Starting window y position, if applicable
    i16 start_pos_y;

    // Starting window width, if applicable
    i16 start_width;

    // Starting window height, if applicable
    i16 start_height;

    // The application name, if applicable
    char* name;
} application_config;

GE_API b8 application_create(struct game* game_inst);

GE_API b8 application_run();