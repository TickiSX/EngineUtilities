#pragma once

#include <cmath>

namespace EngineUtilities {

/**
 * @brief Matriz 3x3 para transformaciones 2D homogéneas.
 */
struct Matrix3x3 {
    float m[3][3];

    Matrix3x3(float diag = 1.0f) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                m[i][j] = (i == j) ? diag : 0.0f;
    }

    static Matrix3x3 identity() { return Matrix3x3(1.0f); }

    Matrix3x3 transpose() const {
        Matrix3x3 result;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                result.m[i][j] = m[j][i];
        return result;
    }

    float determinant() const {
        return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
               m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
               m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    }

    // Inversa no implementada aún por simplicidad
};

}