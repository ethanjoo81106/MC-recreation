#include "Camera.h"

#include "Input.h"

#include <GLFW/glfw3.h>

#include <cmath>

namespace {
constexpr float kPi = 3.14159265358979323846F;

float toRadians(float degrees) {
    return degrees * (kPi / 180.0F);
}

float length(const Vec3& value) {
    return std::sqrt(value.x * value.x + value.y * value.y + value.z * value.z);
}

Vec3 normalize(const Vec3& value) {
    const float magnitude = length(value);

    if (magnitude == 0.0F) {
        return {};
    }

    return {value.x / magnitude, value.y / magnitude, value.z / magnitude};
}

Vec3 cross(const Vec3& lhs, const Vec3& rhs) {
    return {
        lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.x * rhs.y - lhs.y * rhs.x
    };
}

Vec3 getGroundForwardFromYaw(float yawDegrees) {
    const float viewYawRadians = toRadians(yawDegrees + 90.0F);
    return {-std::sin(viewYawRadians), 0.0F, -std::cos(viewYawRadians)};
}

Vec3 getGroundRightFromYaw(float yawDegrees) {
    const float viewYawRadians = toRadians(yawDegrees + 90.0F);
    return {std::cos(viewYawRadians), 0.0F, -std::sin(viewYawRadians)};
}
}

Camera::Camera()
    : m_position({0.0F, 0.0F, 3.0F}) {}

void Camera::update(const Input& input, float deltaTime) {
    if (input.isCursorCaptured()) {
        m_yawDegrees -= input.getMouseDeltaX() * m_mouseSensitivity;
        m_pitchDegrees -= input.getMouseDeltaY() * m_mouseSensitivity;

        if (m_pitchDegrees > 89.0F) {
            m_pitchDegrees = 89.0F;
        }

        if (m_pitchDegrees < -89.0F) {
            m_pitchDegrees = -89.0F;
        }
    }

    const float frameSpeed = m_moveSpeed * deltaTime;
    const Vec3 forward = normalize(getGroundForwardFromYaw(m_yawDegrees));
    const Vec3 right = normalize(getGroundRightFromYaw(m_yawDegrees));
    const Vec3 worldUp{0.0F, 1.0F, 0.0F};

    if (input.isKeyDown(GLFW_KEY_W)) {
        m_position += forward * frameSpeed;
    }

    if (input.isKeyDown(GLFW_KEY_S)) {
        m_position -= forward * frameSpeed;
    }

    if (input.isKeyDown(GLFW_KEY_D)) {
        m_position += right * frameSpeed;
    }

    if (input.isKeyDown(GLFW_KEY_A)) {
        m_position -= right * frameSpeed;
    }

    if (input.isKeyDown(GLFW_KEY_SPACE)) {
        m_position += worldUp * frameSpeed;
    }

    if (input.isKeyDown(GLFW_KEY_LEFT_CONTROL)) {
        m_position -= worldUp * frameSpeed;
    }
}

const Vec3& Camera::getPosition() const {
    return m_position;
}

Vec3 Camera::getForward() const {
    const float yawRadians = toRadians(m_yawDegrees);
    const float pitchRadians = toRadians(m_pitchDegrees);

    return normalize({
        std::cos(yawRadians) * std::cos(pitchRadians),
        std::sin(pitchRadians),
        std::sin(yawRadians) * std::cos(pitchRadians)
    });
}

float Camera::getYawDegrees() const {
    return m_yawDegrees;
}

float Camera::getPitchDegrees() const {
    return m_pitchDegrees;
}

Vec3 Camera::getRight() const {
    const Vec3 worldUp{0.0F, 1.0F, 0.0F};
    return normalize(cross(getForward(), worldUp));
}
