#pragma once
#include "Particle.h"

class Projectile : public Particle {
private:
	float mass = 1.0f;
public:
	Projectile(Vector3D position, Vector3D velocity, float mass, float damping, IntegratorType type);

	void update(double t) override;
};

