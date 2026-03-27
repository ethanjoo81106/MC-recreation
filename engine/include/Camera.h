#pragma once

#include "Vec3.h"

class Input;

class Camera {
public:
    Camera();

    void update(const Input& input, float deltaTime);

    const Vec3& getPosition() const;
    Vec3 getForward() const;
    float getYawDegrees() const;
    float getPitchDegrees() const;

private:
    Vec3 getRight() const;

    Vec3 m_position;
    float m_yawDegrees = -90.0F;
    float m_pitchDegrees = 0.0F;
    float m_moveSpeed = 5.0F;
    float m_mouseSensitivity = 0.12F;
};
