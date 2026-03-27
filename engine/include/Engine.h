#pragma once
#include <memory>

class Application;

class Window;

class Engine {
public:
    explicit Engine(Application& application);
    ~Engine();
    void run();

private:
    Application& m_application;
    std::unique_ptr<Window> m_window;
};
