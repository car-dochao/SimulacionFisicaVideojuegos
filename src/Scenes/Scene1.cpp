#include "Scene1.h"
#include "RenderUtils.hpp"
#include "Vector3D.h"
#include "Particle.h"
#include "Projectile.h"

Scene1::Scene1(std::string name) : 
    Scene(name), shoot_mass(10.0f), shoot_velocity(10.0f),
    gravity(0, -9.8f, 0) {

}

void Scene1::init() {
    // Añadimos una partícula
    //m_particles.push_back(new Particle({0, 0, 0}, {2, 0, 0})); // velocidad 2m/s?

    // Esfera que sirve como diana
    physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(1.0f));
    m_transform = physx::PxTransform(physx::PxVec3(0.0f, 10.0f, 0.0f));
    m_renderItems.push_back(new RenderItem(sphere, &m_transform, Vector4(1.0f, 0.1f, 0.1f, 1.0f)));
}

void Scene1::update(double dt) {
    for (Particle* particle : m_particles)
        if (particle) particle->update(dt);
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

void Scene1::keyPress(unsigned char key, const physx::PxTransform& cameraTransform) {
    // Teclas globales de navegación entre prácticas
    switch (key) {
    case 'e': // disparar proyectil
        shoot();
        return;
    case 'm': // elevar masa del proximo proyectil
        shoot_mass++;
        return;
    case 'M': // restar masa del proximo proyectil (shift + m)
        shoot_mass--;
        return;
    case 'v': // sumar velocidad del proximo proyectil
        shoot_velocity++;
        return;
    case 'V': // restar velociad del proximo proyectil (shift + V)
        shoot_velocity--;
        return;
    }
}

void Scene1::shoot() {
    Vector3D direction = (Vector3D(GetCamera()->getDir()).normalize() * shoot_velocity);
    m_particles.push_back(new Projectile(GetCamera()->getEye(), direction, shoot_mass));
}
