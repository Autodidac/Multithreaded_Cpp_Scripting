
#pragma once
#include <string_view>
#include <cstdint>

namespace aui {

struct vec2 { float x, y; };

enum class event_type {
    none,
    mouse_down,
    mouse_up,
    mouse_move
};

struct input_event {
    event_type type;
    vec2 mouse_pos;
    uint8_t mouse_button;
};

void begin_frame(float dt, vec2 mouse_pos, bool mouse_down);
void end_frame();

void begin_window(std::string_view title, vec2 pos, vec2 size);
void end_window();

bool button(std::string_view label, vec2 size);
void label(std::string_view text);

void push_input(const input_event& e);

} // namespace aui
