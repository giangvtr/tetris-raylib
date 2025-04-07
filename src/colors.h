//
// Created by giangvu on 4/7/25.
//

#ifndef COLORS_H
#define COLORS_H
#pragma once

#include <vector>
#include <raylib.h>

extern const Color darkGrey;    // 0 - Dark grey (empty cell)
extern const Color lightPink;  // 1 - Light Pink (rosy)
extern const Color pink;  // 2 - Pink (classic feminine)
extern const Color orchid;  // 3 - Orchid (pastel violet-pink)
extern const Color babyBlue;  // 4 - Baby Blue (soft and calming)
extern const Color peach;  // 5 - Peach (warm and friendly)
extern const Color plum;  // 6 - Plum (sophisticated softness)
extern const Color blush;   // 7 - Lavender Blush (almost white, gentle)


std::vector<Color> GetCellColors();

#endif //COLORS_H
