#pragma once

class Input;
class Window;

class Application {
public:
    virtual ~Application() = default;

    virtual void onStart(Window& window) {}
    virtual void onUpdate(float deltaTime, const Input& input) = 0;
    virtual void onRender() = 0;
};
