#include "Scene1.h"
#include "RenderUtils.hpp"
#include "Vector3D.h"
#include "Particle.h"

void Scene1::init() {
    // Añadimos una partícula
    m_particles.push_back(new Particle({0, 0, 0}, {2, 0, 0})); // velocidad 2m/s?
}

void Scene1::update(double dt) {
    for (Particle* particle : m_particles)
        if (particle) particle->integrate(dt);
}

void Scene1::cleanup() {
    for (RenderItem* item : m_renderItems)
        if (item) {
            item->release(); // Deregistra y destruye el item
            item = nullptr;
        }

    for (Particle* particle : m_particles)
        if (particle) delete particle;
}