#include "Projectile.h"
#include "Particle.h"

Projectile::Projectile(Vector3D position, Vector3D velocity, float mass, float damping, IntegratorType type)
	: Particle(position, velocity, damping, type) {

}

void Projectile::update(double t) {
	Particle::update(t); // integrates as particle



}