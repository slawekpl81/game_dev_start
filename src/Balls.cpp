#include "Balls.hpp"
#include "raylib.h"

BallsSystem::BallsSystem() {
  _position.reserve(100);
  _velocity.reserve(100);
  _radius.reserve(100);
  _color.reserve(100);
}

void BallsSystem::add_random_ball() {

  const float random_x = (float)GetRandomValue(50, GetScreenWidth() - 50);
  const float random_y = (float)GetRandomValue(50, GetScreenHeight() - 50);
  const int random_color = GetRandomValue(0, 5);
  switch (random_color) {
  case 0:
    _color.push_back(RED);
    break;
  case 1:
    _color.push_back(GREEN);
    break;
  case 2:
    _color.push_back(BLUE);
    break;
  case 3:
    _color.push_back(YELLOW);
    break;
  case 4:
    _color.push_back(MAGENTA);
    break;
  case 5:
    _color.push_back(GRAY);
    break;
  }

  _position.push_back(Vector2{random_x, random_y});
  _velocity.push_back(Vector2{5, 5});
  _radius.push_back(10);
}

void BallsSystem::remove_ball(int index) {

  // Zamieniamy z ostatnim elementem
  _position[index] = _position.back();
  _velocity[index] = _velocity.back();
  _radius[index] = _radius.back();
  _color[index] = _color.back();

  // Usuwamy ostatni (teraz zdublowany) element
  _position.pop_back();
  _velocity.pop_back();
  _radius.pop_back();
  _color.pop_back();
}

void BallsSystem::draw() {
  for (int i = 0; i < _position.size(); i++) {
    DrawCircleV(_position[i], _radius[i], _color[i]);
  }
}

void BallsSystem::update() {

  for (int i = _position.size() - 1; i >= 0; i--) {
    _position[i].x += _velocity[i].x;
    _position[i].y += _velocity[i].y;
  }
}

bool BallsSystem::is_ball_in_screen(int index) {
  return _position[index].x >= 0 && _position[index].x <= GetScreenWidth() &&
         _position[index].y >= 0 && _position[index].y <= GetScreenHeight();
}

int BallsSystem::get_number_of_balls() { return _position.size(); }

void BallsSystem::remove_balls_out_of_screen() {
  // Iterujemy od końca, żeby nie zepsuć indeksów przy usuwaniu
  for (int i = _position.size() - 1; i >= 0; i--) {
    if (!is_ball_in_screen(i)) {
      remove_ball(i);
    }
  }
}

void BallsSystem::bounce_from_borders_of_screen() {
  for (int i = _position.size() - 1; i >= 0; i--) {
    if (_position[i].x + _radius[i] >= GetScreenWidth() ||
        _position[i].x - _radius[i] <= 0) {
      _velocity[i].x = -_velocity[i].x;
    }
    if (_position[i].y + _radius[i] >= GetScreenHeight() ||
        _position[i].y - _radius[i] <= 0) {
      _velocity[i].y = -_velocity[i].y;
    }
  }
}