#pragma once

#include <cmath>

namespace EngineUtilities {

/**
 * @brief Matriz 4x4 para transformaciones 3D.
 */
struct Matrix4x4 {
    float m[4][4];

    Matrix4x4(float diag = 1.0f) {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                m[i][j] = (i == j) ? diag : 0.0f;
    }

    static Matrix4x4 identity() { return Matrix4x4(1.0f); }

    Matrix4x4 transpose() const {
        Matrix4x4 result;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                result.m[i][j] = m[j][i];
        return result;
    }

    // Determinante e inversa no implementadas por simplicidad inicial

    static Matrix4x4 translate(float tx, float ty, float tz) {
        Matrix4x4 result = identity();
        result.m[0][3] = tx;
        result.m[1][3] = ty;
        result.m[2][3] = tz;
        return result;
    }

    static Matrix4x4 scale(float sx, float sy, float sz) {
        Matrix4x4 result = identity();
        result.m[0][0] = sx;
        result.m[1][1] = sy;
        result.m[2][2] = sz;
        return result;
    }

    static Matrix4x4 rotateX(float angle) {
        Matrix4x4 result = identity();
        float c = std::cos(angle), s = std::sin(angle);
        result.m[1][1] = c; result.m[1][2] = -s;
        result.m[2][1] = s; result.m[2][2] = c;
        return result;
    }

    static Matrix4x4 rotateY(float angle) {
        Matrix4x4 result = identity();
        float c = std::cos(angle), s = std::sin(angle);
        result.m[0][0] = c; result.m[0][2] = s;
        result.m[2][0] = -s; result.m[2][2] = c;
        return result;
    }

    static Matrix4x4 rotateZ(float angle) {
        Matrix4x4 result = identity();
        float c = std::cos(angle), s = std::sin(angle);
        result.m[0][0] = c; result.m[0][1] = -s;
        result.m[1][0] = s; result.m[1][1] = c;
        return result;
    }
};

}