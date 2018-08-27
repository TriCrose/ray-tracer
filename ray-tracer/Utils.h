#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <limits>

namespace Utils {
    constexpr float kPi = 3.14159f;
    constexpr float kEpsilon = 0.01f;
    constexpr float kInfinity = std::numeric_limits<float>::infinity();
    
    inline float ToRadians(float degrees) { return degrees * kPi/180.0f; }
    inline float ToDegrees(float radians) { return radians * 180.0f/kPi; }
}

#endif // UTILS_H