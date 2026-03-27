#include "Input.h"

#include "Window.h"

Input::Input(Window& window)
    : m_window(window) {}

void Input::beginFrame() {
    double cursorX = 0.0;
    double cursorY = 0.0;
    m_window.getCursorPosition(cursorX, cursorY);

    if (m_hasPreviousCursorPosition && m_window.isCursorCaptured()) {
        m_mouseDeltaX = static_cast<float>(cursorX - m_previousCursorX);
        m_mouseDeltaY = static_cast<float>(cursorY - m_previousCursorY);
    } else {
        m_mouseDeltaX = 0.0F;
        m_mouseDeltaY = 0.0F;
    }

    m_previousCursorX = cursorX;
    m_previousCursorY = cursorY;
    m_hasPreviousCursorPosition = true;
}

bool Input::isKeyDown(int key) const {
    return m_window.isKeyPressed(key);
}

float Input::getMouseDeltaX() const {
    return m_mouseDeltaX;
}

float Input::getMouseDeltaY() const {
    return m_mouseDeltaY;
}

void Input::setCursorCaptured(bool captured) const {
    m_window.setCursorCaptured(captured);
}

bool Input::isCursorCaptured() const {
    return m_window.isCursorCaptured();
}
