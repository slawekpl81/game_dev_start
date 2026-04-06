#pragma once

#include <string>
#include <vector>

#include "raylib.h"

class DebugText {
public:
  DebugText();
  ~DebugText() = default;

  void add_text(const std::string &text);
  void draw();
  void clear();

  std::vector<std::string> _debug_text;
  int _x;
  int _y;
  int _font_size;
  Color _color;
};