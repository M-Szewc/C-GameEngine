#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"

// Externally-defined function to create a game
extern b8 create_game(game* out_game);

// Entry point of the application
int main(void) {
    
    // Request the game instance from the application
    game game_inst;
    if (!create_game(&game_inst)) {
        GE_FATAL("Could not create game!");
        return -1;
    }

    // Ensure that function pointers exist
    if (!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize) {
        GE_FATAL("The game's function pointers must be assigned!");
        return -2;
    }

    
    // Initialize the application
    if(!application_create(&game_inst)) {
        GE_ERROR("Application failed to create!");
        return 1;
    }

    // Run the application
    if(!application_run()) {
        GE_WARN("Application did not shutdown gracefully!");
        return 2;
    }

    return 0;
}