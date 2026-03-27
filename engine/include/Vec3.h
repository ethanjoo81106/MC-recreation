#pragma once

struct Vec3 {
    float x = 0.0F;
    float y = 0.0F;
    float z = 0.0F;

    Vec3& operator+=(const Vec3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vec3& operator-=(const Vec3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }
};

inline Vec3 operator+(Vec3 lhs, const Vec3& rhs) {
    lhs += rhs;
    return lhs;
}

inline Vec3 operator-(Vec3 lhs, const Vec3& rhs) {
    lhs -= rhs;
    return lhs;
}

inline Vec3 operator*(Vec3 value, float scalar) {
    value.x *= scalar;
    value.y *= scalar;
    value.z *= scalar;
    return value;
}

inline Vec3 operator*(float scalar, Vec3 value) {
    return value * scalar;
}
