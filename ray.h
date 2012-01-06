#ifndef RAY_H
#define RAY_H

#include "point.h"
#include "vector.h"

class Ray {
public:
	Ray();
	Ray(Vector &start, Vector &direction);

	const Vector& getStart() const;
	const Vector& getDirection() const;

private:
	Vector start;
	Vector direction;

	friend std::ostream& operator<<(std::ostream& out, const Ray& r);
};

#endif
