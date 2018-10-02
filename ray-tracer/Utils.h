#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <limits>
#include <chrono>

namespace Utils {
    constexpr float kPi         {3.14159f};
    constexpr float kEpsilon    {0.01f};
    constexpr float kInfinity   {std::numeric_limits<float>::infinity()};

    constexpr float ToRadians(float degrees) { return degrees * kPi/180.0f; }
    constexpr float ToDegrees(float radians) { return radians * 180.0f/kPi; }

    inline auto Time() {
        using namespace std::chrono;
        auto epoch = time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch();
        return duration_cast<milliseconds>(epoch).count();
    }
}

#endif // UTILS_H