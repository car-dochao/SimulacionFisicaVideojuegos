#pragma once

#include "Scene.h"
#include "RenderUtils.hpp"

class Particle;

class Scene1 : public Scene {

private:
    physx::PxTransform m_transform;
    std::vector<RenderItem*> m_renderItems;
    std::vector<Particle*> m_particles;

public:
    explicit Scene1(std::string name) : Scene(std::move(name)) {}

    void init() override;
    void update(double dt) override;
    void cleanup() override;
};