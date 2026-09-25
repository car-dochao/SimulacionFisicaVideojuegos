#pragma once

#include <PxPhysicsAPI.h>
#include <cmath>

class Vector3D {

private:
	float x, y, z;

public:
	Vector3D() : x(0), y(0), z(0) {};
	Vector3D(float x, float y, float z) : x(x), y(y), z(z) {};
	Vector3D(physx::PxVec3 v) : x(v.x), y(v.y), z(v.z) {};

	// Setters
	inline void setX(float x) { this->x = x; }
	inline void setY(float y) { this->y = y; }
	inline void setZ(float z) { this->z = z; }

	// Getters
	inline float getX() const { return x; }
	inline float getY() const { return y; }
	inline float getZ() const { return z; }

	// Magnitud de un Vector3D
	inline float magnitude() const { return std::sqrt(x * x + y * y + z * z); }

	// Devuelve un Vector3D normalizado
	inline Vector3D normalize() const {
		float mag = magnitude();
		return Vector3D(x / mag, y / mag, z / mag);
	}

	inline Vector3D& operator= (const Vector3D& v) {
		return Vector3D(x = v.x, y = v.y, z = v.z);
	}

	inline Vector3D& operator+ (const Vector3D& v) {
		return Vector3D(x + v.x, y + v.y, z + v.z);
	}

	inline Vector3D& operator- (const Vector3D& v) {
		return Vector3D(x - v.x, y - v.y, z - v.z);
	}

	inline Vector3D& operator* (float n) {
		return Vector3D(x * n, y * n, z * n);
	}

	inline Vector3D& operator/ (float n) {
		return Vector3D(x / n, y / n, z / n);
	}

	inline Vector3D& operator+= (const Vector3D& v) {
		return Vector3D(x += v.x, y+= v.y, z += v.z);
	}

	// Producto escalar
	inline float dot(const Vector3D& v) const {
		return (x * v.x + y * v.y + z * v.z);
	}

	// Producto vectorial
	inline Vector3D& cross(const Vector3D& v) const {
		return Vector3D(y * v.z - z * v.y, x * v.z - z * v.x, x * v.y - y * v.x);
	}

	// Conversión a physx por operador
	inline operator physx::PxVec3() const { return physx::PxVec3(x, y, z); }
};
