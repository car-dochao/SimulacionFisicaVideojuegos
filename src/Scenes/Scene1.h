#pragma once

#include "Scene.h"
#include "RenderUtils.hpp"
#include "Vector3D.h"

class Particle;

class Scene1 : public Scene {

private:
    physx::PxTransform m_transform;
    std::vector<RenderItem*> m_renderItems;
    std::vector<Particle*> m_particles;

    // atributos de la escena (disparo, gravedad)
    float shoot_mass;
    float shoot_velocity;
    Vector3D gravity;

    void shoot(); // dispara un proyectil desde la cámara

public:
    explicit Scene1(std::string name);

    void init() override;
    void update(double dt) override;
    void cleanup() override;
    void keyPress(unsigned char key, const physx::PxTransform& cameraTransform) override;
};