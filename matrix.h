#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
public:
	Matrix(); // Empty constructor sets all elements to 0

	void identity(); // set elements to identity matrix
	Matrix inverse();
	void zero(); // zero out matrix
	double getXY(int x, int y);
	void setXY(int x, int y, double value);
	void set(int i, double value);
	void set(double (&arr)[16]);
	void set(const Matrix& matrix);
	// overloaded operators +, -, *, /, (x,y)
	// matrix * vector
	// matrix * scalar

	friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator*(const Matrix& lhs, const double scalar);
	
	double operator()(const int col, const int row);
	void operator()(); // zero out matrix
	void operator=(const Matrix& matrix);
	bool operator==(const Matrix& matrix);
	// determinant?

	friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix);

private:
	double elems[16]; // or row major order
};

#endif
