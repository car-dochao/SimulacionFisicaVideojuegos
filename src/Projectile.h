#pragma once
#include "Particle.h"

class Projectile : public Particle {
protected:
	Vector3D gravity; // gravedad simulada del proyectil

public:
	Projectile(Vector3D position, Vector3D direction, float real_mass,
		Vector3D gravity, float sim_velocity, float real_velocity,
		float damping = 1.f, IntegratorType type = IntegratorType::SemiEuler);

	void update(double t) override;
};
