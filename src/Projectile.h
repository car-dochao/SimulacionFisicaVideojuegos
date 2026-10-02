#pragma once
#include "Particle.h"

class Projectile : public Particle {
protected:
	float mass = 1.0f;
public:
	Projectile(Vector3D position, Vector3D velocity, float mass, float damping = 0.98, IntegratorType type = IntegratorType::SemiEuler);

	void update(double t) override;
};
