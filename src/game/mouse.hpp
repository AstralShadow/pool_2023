#ifndef INCLUDE_MOUSE_HPP
#define INCLUDE_MOUSE_HPP

#include "utils/point.hpp"


namespace game
{
    enum MouseMode {
        MM_NONE,
        MM_CUE
    } extern mouse_mode;

    extern Point drag_start;
}

#endif // INCLUDE_MOUSE_HPP
