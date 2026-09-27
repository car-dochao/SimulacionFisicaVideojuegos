#pragma once

#include "Vector3D.h"
#include "RenderUtils.hpp"

class Particle {

private:
	RenderItem* item;

	Vector3D velocity;
	Vector3D acceleration;
	physx::PxTransform transform; // transform de nuestra particula, position + quaternion
	Vector3D lastPos; // para Verlet

	float mass = 1.0f;
	float damping = 0.98; // valor por defecto del damping

public:
	enum class IntegratorType { Euler, SemiEuler, Verlet };

	Particle(Vector3D position, Vector3D velocity, float damping = 0.98, IntegratorType type = IntegratorType::Euler);
	~Particle();

	void integrate(double t);
	void applyForce(float force, Vector3D direction);

private:
	IntegratorType intg_type; // por defecto Euler según ctra

	// métodos para cada tipo de integrador
	void intg_euler(double t);
	void intg_semiEuler(double t);
	void intg_verlet(double t);
};