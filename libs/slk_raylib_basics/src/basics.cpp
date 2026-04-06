#include "basics.hpp"

#include "raylib.h"

DebugText::DebugText() {
  _x = 10;
  _y = 10;
  _font_size = 20;
  _color = BLACK;
}

void DebugText::add_text(const std::string &text) {
  _debug_text.push_back(text);
}

void DebugText::draw() {
  for (int i = 0; i < _debug_text.size(); i++) {
    DrawText(_debug_text[i].c_str(), _x, _y + i * 20, _font_size, _color);
  }

  clear();
}

void DebugText::clear() { _debug_text.clear(); }