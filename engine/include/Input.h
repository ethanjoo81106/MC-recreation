#pragma once

class Window;

class Input {
public:
    explicit Input(Window& window);

    void beginFrame();

    bool isKeyDown(int key) const;
    float getMouseDeltaX() const;
    float getMouseDeltaY() const;
    void setCursorCaptured(bool captured) const;
    bool isCursorCaptured() const;

private:
    Window& m_window;
    double m_previousCursorX = 0.0;
    double m_previousCursorY = 0.0;
    float m_mouseDeltaX = 0.0F;
    float m_mouseDeltaY = 0.0F;
    bool m_hasPreviousCursorPosition = false;
};
