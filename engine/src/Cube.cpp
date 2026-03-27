#include "Cube.h"

#include <GLFW/glfw3.h>

Cube::Cube(Vec3 position, float size)
    : m_position(position), m_size(size) {}

void Cube::render() const {
    const float halfSize = m_size * 0.5F;

    glPushMatrix();
    glTranslatef(m_position.x, m_position.y, m_position.z);

    glBegin(GL_QUADS);

    glColor3f(0.80F, 0.23F, 0.18F);
    glVertex3f(-halfSize, -halfSize, halfSize);
    glVertex3f(halfSize, -halfSize, halfSize);
    glVertex3f(halfSize, halfSize, halfSize);
    glVertex3f(-halfSize, halfSize, halfSize);

    glColor3f(0.18F, 0.62F, 0.25F);
    glVertex3f(-halfSize, -halfSize, -halfSize);
    glVertex3f(-halfSize, halfSize, -halfSize);
    glVertex3f(halfSize, halfSize, -halfSize);
    glVertex3f(halfSize, -halfSize, -halfSize);

    glColor3f(0.22F, 0.42F, 0.84F);
    glVertex3f(-halfSize, -halfSize, -halfSize);
    glVertex3f(-halfSize, -halfSize, halfSize);
    glVertex3f(-halfSize, halfSize, halfSize);
    glVertex3f(-halfSize, halfSize, -halfSize);

    glColor3f(0.95F, 0.76F, 0.21F);
    glVertex3f(halfSize, -halfSize, -halfSize);
    glVertex3f(halfSize, halfSize, -halfSize);
    glVertex3f(halfSize, halfSize, halfSize);
    glVertex3f(halfSize, -halfSize, halfSize);

    glColor3f(0.79F, 0.35F, 0.73F);
    glVertex3f(-halfSize, halfSize, -halfSize);
    glVertex3f(-halfSize, halfSize, halfSize);
    glVertex3f(halfSize, halfSize, halfSize);
    glVertex3f(halfSize, halfSize, -halfSize);

    glColor3f(0.15F, 0.72F, 0.78F);
    glVertex3f(-halfSize, -halfSize, -halfSize);
    glVertex3f(halfSize, -halfSize, -halfSize);
    glVertex3f(halfSize, -halfSize, halfSize);
    glVertex3f(-halfSize, -halfSize, halfSize);

    glEnd();
    glPopMatrix();
}
