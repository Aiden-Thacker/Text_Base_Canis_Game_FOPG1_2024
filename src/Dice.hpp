#pragma once
#include <vector>
#include <random>
#include <time.h>

#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"

extern std::vector<int> Roll(int _num, int _sides);

extern int RollSum(int _num, int _sides);

extern void Print(std::vector<int>);