add_library(engine STATIC src/Camera.cpp src/Cube.cpp src/Engine.cpp src/Input.cpp src/Window.cpp)

find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(engine PUBLIC glfw opengl32)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(engine PUBLIC cxx_std_20)
