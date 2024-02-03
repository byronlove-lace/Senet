#ifndef NCURSES_TOOLS_H
#define NCURSES_TOOLS_H

#include <vector>
#include <cmath>
#include <cstring>
#include <ncurses.h>

using std::vector;
using std::round;
using std::strlen;

int percentile_to_position(int max, float percent);

size_t longest_string(vector <const char *> strVect);

#endif
