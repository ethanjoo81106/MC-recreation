#pragma once

struct GLFWwindow;

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    Window(const Window&) = delete;

    /*
    *Window& operator=(const Window&) {
        throw std::logic_error("Assignment not allowed");
    }

    Line below is the same thing as this
     */
    Window& operator=(const Window&) = delete;

    bool shouldClose() const;
    void pollEvents();
    void swapBuffers();
    bool isKeyPressed(int key) const;
    void getCursorPosition(double& x, double& y) const;
    void getFramebufferSize(int& width, int& height) const;
    void setCursorCaptured(bool captured);
    bool isCursorCaptured() const;

private:
    GLFWwindow* m_window = nullptr;
};
