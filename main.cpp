#include <iostream>
#include <string>
#include <vector>

#include "raylib.h"

#include "basics.hpp"

int main() {
  std::cout << "Game Dev Lab 1" << std::endl;

  //--------------------------------------------------------------------------------------
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Game Dev Lab 1");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  std::vector<std::string> debug_text;
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    draw_debug_text(debug_text);

    // DrawText("cool window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
    auto frame_time = GetFrameTime();
    auto fps = GetFPS();
    debug_text.clear();
    debug_text.push_back("Time: " + std::to_string(frame_time));
    debug_text.push_back("FPS: " + std::to_string(fps));
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
