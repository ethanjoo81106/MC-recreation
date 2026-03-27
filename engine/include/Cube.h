#pragma once

#include "Vec3.h"

class Cube {
public:
    Cube(Vec3 position, float size);

    void render() const;

private:
    Vec3 m_position;
    float m_size = 1.0F;
};
