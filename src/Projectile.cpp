#include "Projectile.h"

Projectile::Projectile(Vector3D position, Vector3D direction, float real_mass,
	Vector3D gravity, float sim_velocity, float real_velocity,
	float damping, IntegratorType type) : 
    Particle(position, direction, real_mass, damping, type) {
	// aplicamos la dirección normalizada a la velocidad (simulada)
	velocity = direction.normalize() * sim_velocity;

	// masa y gravedad simuladas
	mass = real_mass * (real_velocity * real_velocity) / (sim_velocity * sim_velocity);
	this->gravity = gravity * (sim_velocity * sim_velocity) / (real_velocity * real_velocity);
}

void Projectile::update(double t) {
    
	acceleration += gravity;
	
	Particle::update(t); // integra la partícula
}
