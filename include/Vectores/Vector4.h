#pragma once

#include <cmath>
#include <string>
#include <sstream>

namespace EngineUtilities {

/**
 * @brief Representa un vector 4D.
 */
struct Vector4 {
    float x, y, z, w;

    Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f)
        : x(x), y(y), z(z), w(w) {}

    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    Vector4 normalized() const {
        float mag = magnitude();
        return mag > 0 ? Vector4(x / mag, y / mag, z / mag, w / mag) : Vector4();
    }

    float dot(const Vector4& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    std::string toString() const {
        std::ostringstream ss;
        ss << "(" << x << ", " << y << ", " << z << ", " << w << ")";
        return ss.str();
    }
};

}