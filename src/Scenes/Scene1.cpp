#include "Scene1.h"
#include "RenderUtils.hpp"
#include "Vector3D.h"
#include "Particle.h"
#include "Projectile.h"

void Scene1::init() {
    // Añadimos una partícula
    m_particles.push_back(new Particle({0, 0, 0}, {2, 0, 0})); // velocidad 2m/s?
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
    case 'E': // disparar
        // creamos una particula y le aplicamos una fuerza
        // quaternion a vector3d 
        Vector3D direction = cameraTransform.q.rotate(Vector3D(0, 0, -1));

        // calculamos la velocidad segun a donde mira la cámara?
        m_particles.push_back(Projectile(cameraTransform.p, direction.normalize(), 1.0));
        return; // Consumimos el evento para que no interfiera con la escena

    case 'O': // elevar masa del proximo proyectil
        return;

    case '': // restar masa del proximo proyectil
        return;

    case '': // sumar velocidad del proximo proyectil
        return;

    case '': // restar velociadd del proximo proyectil
        return;
    }
}

void Scene1::shoot(Vector3D pos, Vector3D direction, float speed, float gravity, float damp, float mass) {
    float adjusted_speed = maths::remap(s);
    Vector3D adjusted_velocity = adjusted_speed * direction.normalize();
    float adjusted_mass = mass * std::pow(speed / adjusted_speed, 2);
    float adjusted_gravity = gravity * std::pow(adjusted_speed / speed, 2);
    Vector3D adjusted_acceleration = Vector3D(0.0f, adjusted_gravity, 0.0f);

    particle_vector.push_back(new Particle(pos, adjusted_velocity, adjusted_acceleration, 0.98f, adjusted_mass));
}