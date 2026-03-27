#include "Engine.h"
#include "Application.h"
#include "Input.h"
#include "Window.h"

#include <GLFW/glfw3.h>
#include <chrono>
#include <memory>

Engine::Engine(Application& application)
    : m_application(application) {}

Engine::~Engine() = default;

void Engine::run() {
    m_window = std::make_unique<Window>(1280, 720, "McRecreation");
    Input input(*m_window);
    glEnable(GL_DEPTH_TEST);
    m_application.onStart(*m_window);
    auto previousFrameTime = std::chrono::steady_clock::now();

    while (!m_window->shouldClose()) {
        const auto currentFrameTime = std::chrono::steady_clock::now();
        const std::chrono::duration<float> frameDuration = currentFrameTime - previousFrameTime;
        previousFrameTime = currentFrameTime;

        m_window->pollEvents();
        input.beginFrame();
        m_application.onUpdate(frameDuration.count(), input);
        glClearColor(0.08F, 0.09F, 0.12F, 1.0F);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_application.onRender();
        m_window->swapBuffers();
    }
}
