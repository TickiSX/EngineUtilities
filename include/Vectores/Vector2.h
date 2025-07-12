#pragma once

#include <cmath>
#include <string>
#include <sstream>

namespace EngineUtilities {

/**
 * @brief Representa un vector 2D.
 */
struct Vector2 {
    float x, y;

    Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    float magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2 normalized() const {
        float mag = magnitude();
        return mag > 0 ? Vector2(x / mag, y / mag) : Vector2();
    }

    float dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }

    std::string toString() const {
        std::ostringstream ss;
        ss << "(" << x << ", " << y << ")";
        return ss.str();
    }
};

}