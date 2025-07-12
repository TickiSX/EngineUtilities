#pragma once

#include <cmath>

namespace EngineUtilities {

/**
 * @brief Representa una rotación como cuaternión.
 */
struct Quaternion {
    float w, x, y, z;

    Quaternion(float w = 1.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f)
        : w(w), x(x), y(y), z(z) {}

    float magnitude() const {
        return std::sqrt(w * w + x * x + y * y + z * z);
    }

    Quaternion normalized() const {
        float mag = magnitude();
        return mag > 0 ? Quaternion(w / mag, x / mag, y / mag, z / mag) : Quaternion();
    }

    Quaternion conjugate() const {
        return Quaternion(w, -x, -y, -z);
    }
};

}