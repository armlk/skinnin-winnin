#include "main.h"

#include <stdio.h>

#include "../build/external/raylib-master/src/raylib.h"
#include "../include/resource_dir.h"  // utility header for SearchAndSetResourceDir
#include "structs/Player.h"

int main() {
  // Tell the window to use vsync and work on high DPI displays
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  // Create the window and OpenGL context
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Skinnin' Winnin'");

  // Utility function from resource_dir.h to find the resources folder and set
  // it as the current working directory so we can load from it
  SearchAndSetResourceDir("resources");
  Player p = initPlayer();

  // game loop
  while (!WindowShouldClose())  // run the loop untill the user presses ESCAPE
                                // or presses the Close button on the window
  {
    // drawing
    BeginDrawing();

    // Setup the back buffer for drawing (clear color and depth buffers)
    ClearBackground(WHITE);

    // player loop
    updatePlayer(&p);
    drawPlayer(&p);

    // end the frame and get ready for the next one  (display frame, poll input,
    // etc...)
    EndDrawing();
  }

  // cleanup
  // unload our texture so it can be cleaned up
  UnloadTexture(p.sprite);

  // destroy the window and cleanup the OpenGL context
  CloseWindow();
  return 0;
}
