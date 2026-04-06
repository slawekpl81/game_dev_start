#include "basics.hpp"

#include "raylib.h"

void draw_debug_text(const std::vector<std::string> &debug_text) {
  for (int i = 0; i < debug_text.size(); i++) {
    DrawText(debug_text[i].c_str(), 10, 10 + i * 20, 20, BLACK);
  }
}