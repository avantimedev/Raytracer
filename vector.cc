/*
 * =====================================================================================
 *
 *       Filename:  vector.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/05/2012 20:49:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Johan Astborg (ja), into@avantimedev.net
 *        Company:  avantimedev
 *
 * =====================================================================================
 */

#include "vector.h"

Vector::Vector() {
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
	return out << "Vector: {" << v.x << ", " << v.y << ", " << v.z << "}";
}

Vector operator+(const Vector &vec1, const Vector &vec2) {
	return Vector(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
}

Vector operator-(const Vector &vec1, const Vector &vec2) {
	return Vector(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}

// Dot product
double operator*(const Vector &vec1, const Vector &vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

Vector operator*(const Vector  &vec1, const double scalar) {
 	return Vector(vec1.x * scalar, vec1.y * scalar, vec1.z * scalar);
}

void Vector::operator+=(const Vector &vec) {
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;
}

void Vector::operator-=(const Vector &vec) {
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;
}

void Vector::operator*=(const double scalar) {
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}
