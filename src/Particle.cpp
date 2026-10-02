#include "Particle.h"
#include <cmath>

Particle::Particle(Vector3D position, Vector3D velocity, float damping, IntegratorType type)
	: transform(position), velocity(velocity), acceleration(0, 0, 0), damping(damping), intg_type(type) // acc nula!
	{ // TODO: calcular p0 con EulerSemiImplícito, siguiente integración Verlet (bool firstIntegration?)
	// Creamos una esfera y un render item con dicha geometría
	physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(1.0f));
	item = new RenderItem(sphere, &transform, Vector4(1.0f, 1.0f, 1.0f, 1.0f));
}

Particle::~Particle() {
	//delete render item??
	item->release();
}

// provisional: aplicar una fuerza (en newtons) en una dirección específica
void Particle::applyForce(float force, Vector3D direction) {
	// modificaremos la aceleración sumando a su vector un direction normalizado * force? (o tal vez normalizar todo despues?)
	// aceleración = fuerza/masa (asumimos masa  de 1kg?)
	acceleration += (direction.normalize() * force); // TODO: añadir masa a la particula?	
	// restaurar un frame mas adelante la acceleración a 0?
}


void Particle::update(double t) {
	// integrate
	switch (intg_type) {
	case IntegratorType::Euler: intg_euler(t); break;
	case IntegratorType::SemiEuler: intg_semiEuler(t); break;
	case IntegratorType::Verlet: intg_verlet(t); break;
	}
}

void Particle::intg_euler(double t) {
	// Euler (pos y luego vel)
	transform.p += velocity * t; // cambiamos la componente p (posición) de transform
	velocity += acceleration * t;
	velocity *= pow(damping, t); // aplicamos damping
}

void Particle::intg_semiEuler(double t) {
	// SemiEuler (vel y luego pos)
	velocity += acceleration * t;
	transform.p += velocity * t;
	velocity *= pow(damping, t); // aplicamos damping
}

void Particle::intg_verlet(double t) {
	// Verlet (nueva pos respecto la anterior y la aceleración)
	Vector3D position(transform.p);
	transform.p = position + (position - lastPos) * damping + acceleration * t * t;
	velocity = (transform.p - position) / t;
	lastPos = position;
}
