#include <iostream>
#include <string>

#include "raylib.h"

#include "Balls.hpp"
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

  DebugText debug_text;
  //--------------------------------------------------------------------------------------
  BallsSystem balls_system;
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    balls_system.update();
    balls_system.remove_balls_out_of_screen();
    balls_system.bounce_from_borders_of_screen();
    if (balls_system.get_number_of_balls() < 10) {
      balls_system.add_random_ball();
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);
    balls_system.draw();

    // DrawText("cool window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
    auto frame_time = GetFrameTime();
    auto fps = GetFPS();
    debug_text.add_text("Time: " + std::to_string(frame_time));
    debug_text.add_text("FPS: " + std::to_string(fps));
    debug_text.draw();
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
