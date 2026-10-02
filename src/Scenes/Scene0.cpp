#include "Scene0.h"
#include "RenderUtils.hpp"
#include "Vector3D.h"

void Scene0::init() {
    // Esfera en (0, 0, 0)
    physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transform = physx::PxTransform(physx::PxVec3(0.0f, 10.0f, 0.0f));

    // Se registra el RenderItem exactamente como en la plantilla original
    m_renderItems.push_back(new RenderItem(shape, &m_transform, Vector4(1.0f, 1.0f, 0.0f, 1.0f)));

    Vector3D u(3.0f, 1.0f, 0.0f);
    Vector3D v(0.0f, 4.0f, 0.0f);
}

void Scene0::update(double dt) {
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);
}

void Scene0::cleanup() {
    for (RenderItem* item : m_renderItems)
        if (item) {
            item->release(); // Deregistra y destruye el item
            item = nullptr;
        }
}