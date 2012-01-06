#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
public:
	Vector();
	Vector(double x, double y, double z);

	// double length -- sqrt(v->x*v->x + v->y*v->y + v->z*v->z)
	// double normalize
	// double distance
	// cross ^
	// dot *
	// equals
	// neg

	// double x()
	// double y()
	// double z()

	void operator+=(const Vector &vec);
	void operator-=(const Vector &vec);
	void operator*=(const double scalar);
	//void operator/=(const double scalar);
private:
	double x;
	double y;
	double z;

	friend std::ostream& operator<<(std::ostream& out, const Vector& v);

	friend Vector operator+(const Vector &vec1, const Vector &vec2);
	friend Vector operator-(const Vector &vec1, const Vector &vec2);
	friend double operator*(const Vector &vec1, const Vector &vec2);
	friend Vector operator*(const Vector &vec1, const double scalar);
	//friend Vector operator/(const Vector &vec1, const double scalar);
	//friend bool operator==(const Vector &vec1) const;
	//friend bool operator!=(const Vector &vec1) const;

	// friend dot_product
	// friend cross_product
	// friend normalize
};

#endif
