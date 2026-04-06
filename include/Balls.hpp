#pragma once
#include <vector>

#include "raylib.h"

class BallsSystem {
public:
  BallsSystem();
  ~BallsSystem() = default;

  void add_random_ball();
  void remove_ball(int index);
  void update();
  void draw();

  int get_number_of_balls();

  bool is_ball_in_screen(int index);
  void remove_balls_out_of_screen();
  void bounce_from_borders_of_screen();

  std::vector<Vector2> _position;
  std::vector<Vector2> _velocity;
  std::vector<float> _radius;
  std::vector<Color> _color;
};