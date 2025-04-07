//
// Created by giangvu on 4/7/25.
//

#include "colors.h"

const Color darkGrey = { 50, 50, 50, 255 };    // 0 - Dark grey (empty cell)
const Color lightPink = { 255, 182, 193, 255 };  // 1 - Light Pink (rosy)
const Color pink = { 255, 192, 203, 255 };  // 2 - Pink (classic feminine)
const Color orchid = { 255, 160, 222, 255 };  // 3 - Orchid (pastel violet-pink)
const Color babyBlue = { 186, 225, 255, 255 };  // 4 - Baby Blue (soft and calming)
const Color peach = { 255, 223, 186, 255 };  // 5 - Peach (warm and friendly)
const Color plum = { 221, 160, 221, 255 };  // 6 - Plum (sophisticated softness)
const Color blush = {255, 240, 245, 255};   // 7 - Lavender Blush (almost white, gentle)

std::vector<Color> GetCellColors()
{
    return {darkGrey, lightPink, pink, orchid, babyBlue, peach, plum, blush};
}

