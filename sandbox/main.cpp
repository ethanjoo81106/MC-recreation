#include <Application.h>
#include <Camera.h>
#include <Cube.h>
#include <Engine.h>
#include <Input.h>
#include <Window.h>

#include <GLFW/glfw3.h>

#include <cmath>

namespace {
constexpr float kPi = 3.14159265358979323846F;

void setPerspective(int width, int height, float fieldOfViewDegrees, float nearPlane, float farPlane) {
    const float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
    const float top = std::tan(fieldOfViewDegrees * 0.5F * (kPi / 180.0F)) * nearPlane;
    const float right = top * aspectRatio;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-right, right, -top, top, nearPlane, farPlane);
}

void drawGround(float size, int divisions) {
    const float halfSize = size * 0.5F;
    const float step = size / static_cast<float>(divisions);

    glColor3f(0.28F, 0.32F, 0.28F);
    glBegin(GL_QUADS);
    glVertex3f(-halfSize, -0.51F, -halfSize);
    glVertex3f(halfSize, -0.51F, -halfSize);
    glVertex3f(halfSize, -0.51F, halfSize);
    glVertex3f(-halfSize, -0.51F, halfSize);
    glEnd();

    glColor3f(0.43F, 0.48F, 0.43F);
    glBegin(GL_LINES);

    for (int index = 0; index <= divisions; ++index) {
        const float offset = -halfSize + static_cast<float>(index) * step;
        glVertex3f(offset, -0.5F, -halfSize);
        glVertex3f(offset, -0.5F, halfSize);

        glVertex3f(-halfSize, -0.5F, offset);
        glVertex3f(halfSize, -0.5F, offset);
    }

    glEnd();
}
}

class SandboxApp final : public Application {
public:
    SandboxApp()
        : m_cube({0.0F, 0.0F, 0.0F}, 1.0F) {}

    void onStart(Window& window) override {
        m_window = &window;
        window.setCursorCaptured(true);
    }

    void onUpdate(float deltaTime, const Input& input) override {
        if (input.isKeyDown(GLFW_KEY_ESCAPE)) {
            input.setCursorCaptured(false);
        }

        if (input.isKeyDown(GLFW_KEY_TAB)) {
            input.setCursorCaptured(true);
        }

        m_camera.update(input, deltaTime);
    }

    void onRender() override {
        int framebufferWidth = 1;
        int framebufferHeight = 1;
        m_window->getFramebufferSize(framebufferWidth, framebufferHeight);

        glViewport(0, 0, framebufferWidth, framebufferHeight);
        setPerspective(framebufferWidth, framebufferHeight, 70.0F, 0.1F, 100.0F);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef(-m_camera.getPitchDegrees(), 1.0F, 0.0F, 0.0F);
        glRotatef(-(m_camera.getYawDegrees() + 90.0F), 0.0F, 1.0F, 0.0F);

        const Vec3& position = m_camera.getPosition();
        glTranslatef(-position.x, -position.y, -position.z);

        drawGround(40.0F, 40);
        m_cube.render();
    }

private:
    Window* m_window = nullptr;
    Camera m_camera;
    Cube m_cube;
};

int main() {
    SandboxApp application;
    Engine engine(application);
    engine.run();
    return 0;
}
