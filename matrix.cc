/*
 * =====================================================================================
 *
 *       Filename:  matrix.cc
 *
 *    Description:  Matrix library
 *
 *        Version:  1.0
 *        Created:  01/11/2012 18:36:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Johan Astborg (ja), into@avantimedev.net
 *        Company:  avantimedev
 *
 * =====================================================================================
 */

#include "matrix.h"

Matrix::Matrix() {
	zero();
}

void Matrix::identity() {
	zero();
	elems[0] = 1;
	elems[5] = 1;
	elems[10] = 1;
	elems[15] = 1;
}

bool Matrix::inverse() {
	// Reference: MESA implementation
	
	double inv[16], det;
	int i;

	inv[0] =   elems[5]*elems[10]*elems[15] - elems[5]*elems[11]*elems[14] - elems[9]*elems[6]*elems[15]
	+ elems[9]*elems[7]*elems[14] + elems[13]*elems[6]*elems[11] - elems[13]*elems[7]*elems[10];
	inv[4] =  -elems[4]*elems[10]*elems[15] + elems[4]*elems[11]*elems[14] + elems[8]*elems[6]*elems[15]
	- elems[8]*elems[7]*elems[14] - elems[12]*elems[6]*elems[11] + elems[12]*elems[7]*elems[10];
	inv[8] =   elems[4]*elems[9]*elems[15] - elems[4]*elems[11]*elems[13] - elems[8]*elems[5]*elems[15]
	+ elems[8]*elems[7]*elems[13] + elems[12]*elems[5]*elems[11] - elems[12]*elems[7]*elems[9];
	inv[12] = -elems[4]*elems[9]*elems[14] + elems[4]*elems[10]*elems[13] + elems[8]*elems[5]*elems[14]
	- elems[8]*elems[6]*elems[13] - elems[12]*elems[5]*elems[10] + elems[12]*elems[6]*elems[9];
	inv[1] =  -elems[1]*elems[10]*elems[15] + elems[1]*elems[11]*elems[14] + elems[9]*elems[2]*elems[15]
	- elems[9]*elems[3]*elems[14] - elems[13]*elems[2]*elems[11] + elems[13]*elems[3]*elems[10];
	inv[5] =   elems[0]*elems[10]*elems[15] - elems[0]*elems[11]*elems[14] - elems[8]*elems[2]*elems[15]
	+ elems[8]*elems[3]*elems[14] + elems[12]*elems[2]*elems[11] - elems[12]*elems[3]*elems[10];
	inv[9] =  -elems[0]*elems[9]*elems[15] + elems[0]*elems[11]*elems[13] + elems[8]*elems[1]*elems[15]
	- elems[8]*elems[3]*elems[13] - elems[12]*elems[1]*elems[11] + elems[12]*elems[3]*elems[9];
	inv[13] =  elems[0]*elems[9]*elems[14] - elems[0]*elems[10]*elems[13] - elems[8]*elems[1]*elems[14]
	+ elems[8]*elems[2]*elems[13] + elems[12]*elems[1]*elems[10] - elems[12]*elems[2]*elems[9];
	inv[2] =   elems[1]*elems[6]*elems[15] - elems[1]*elems[7]*elems[14] - elems[5]*elems[2]*elems[15]
	+ elems[5]*elems[3]*elems[14] + elems[13]*elems[2]*elems[7] - elems[13]*elems[3]*elems[6];
	inv[6] =  -elems[0]*elems[6]*elems[15] + elems[0]*elems[7]*elems[14] + elems[4]*elems[2]*elems[15]
	- elems[4]*elems[3]*elems[14] - elems[12]*elems[2]*elems[7] + elems[12]*elems[3]*elems[6];
	inv[10] =  elems[0]*elems[5]*elems[15] - elems[0]*elems[7]*elems[13] - elems[4]*elems[1]*elems[15]
	+ elems[4]*elems[3]*elems[13] + elems[12]*elems[1]*elems[7] - elems[12]*elems[3]*elems[5];
	inv[14] = -elems[0]*elems[5]*elems[14] + elems[0]*elems[6]*elems[13] + elems[4]*elems[1]*elems[14]
	- elems[4]*elems[2]*elems[13] - elems[12]*elems[1]*elems[6] + elems[12]*elems[2]*elems[5];
	inv[3] =  -elems[1]*elems[6]*elems[11] + elems[1]*elems[7]*elems[10] + elems[5]*elems[2]*elems[11]
	- elems[5]*elems[3]*elems[10] - elems[9]*elems[2]*elems[7] + elems[9]*elems[3]*elems[6];
	inv[7] =   elems[0]*elems[6]*elems[11] - elems[0]*elems[7]*elems[10] - elems[4]*elems[2]*elems[11]
	+ elems[4]*elems[3]*elems[10] + elems[8]*elems[2]*elems[7] - elems[8]*elems[3]*elems[6];
	inv[11] = -elems[0]*elems[5]*elems[11] + elems[0]*elems[7]*elems[9] + elems[4]*elems[1]*elems[11]
	- elems[4]*elems[3]*elems[9] - elems[8]*elems[1]*elems[7] + elems[8]*elems[3]*elems[5];
	inv[15] =  elems[0]*elems[5]*elems[10] - elems[0]*elems[6]*elems[9] - elems[4]*elems[1]*elems[10]
	+ elems[4]*elems[2]*elems[9] + elems[8]*elems[1]*elems[6] - elems[8]*elems[2]*elems[5];

	det = elems[0]*inv[0] + elems[1]*inv[4] + elems[2]*inv[8] + elems[3]*inv[12];
	if (det == 0)
	        return false;

	det = 1.0 / det; // Simple optimization for Intel CPUs

	for (i = 0; i < 16; i++)
	        elems[i] = inv[i] * det;

	return true;
}

Vector Matrix::transform(Vector& v) {
	double x  = elems[0] * v.getX() + elems[1] * v.getY() + elems[2] * v.getZ() + elems[3];
	double y  = elems[4] * v.getX() + elems[5] * v.getY() + elems[6] * v.getZ() + elems[7];
	double z  = elems[8] * v.getX() + elems[9] * v.getY() + elems[10] * v.getZ() + elems[11];
	return Vector(x, y, z);
}

void Matrix::zero() {
	for (int i=0;i<16;i++)
			elems[i] = 0;
}

double Matrix::getXY(int x, int y) {
	return elems[x + y*4];
}

void Matrix::setXY(int x, int y, double value) {
	elems[x + y*4] = value;
}

void Matrix::set(int i, double value) {
	elems[i] = value;
}

void Matrix::set(double (&arr)[16]) {
	for (int i=0;i<16;i++)
		elems[i] = arr[i];
}

void Matrix::set(const Matrix& matrix) {
	for (int i=0;i<16;i++)
		elems[i] = matrix.elems[i];
}

double Matrix::operator()(const int col, const int row) {
	return getXY(col, row);
}

void Matrix::operator()() {
	zero();
}

void Matrix::operator=(const Matrix& matrix) {
	set(matrix);
}

bool Matrix::operator==(const Matrix& matrix) {
	for (int i=0;i<16;i++)
		if (elems[i] != matrix.elems[i]) return false;
	return true;
}

// Friends
Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	Matrix m;
	for (int i=0;i<16;i++)
		m.elems[i] = lhs.elems[i] + rhs.elems[i];
	return m;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
	Matrix m;
	for (int i=0;i<16;i++)
		m.elems[i] = lhs.elems[i] - rhs.elems[i];
	return m;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
	Matrix m;
	int	i, j, k;
	for (i = 0; i < 4; i += 1) {
		for (j = 0; j < 4; j += 1) {
			m.elems[j + i*4] = 0.0;
			for (k = 0; k < 4; k += 1) {
				m.elems[j + i*4] += lhs.elems[k + i*4] * rhs.elems[j + k*4];
			}
		}
	}
	return m;
}

Matrix operator*(const Matrix& lhs, const double scalar) {
	Matrix m;
	for (int i=0;i<16;i++)
		m.elems[i] = lhs.elems[i] * scalar;
	return m;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
	out << "Matrix:" << std::endl;
	for (int x=0;x<4;x++) {
		for (int y=0;y<4;y++)
			out << matrix.elems[y + x*4] << " ";
		if (x<3)
		out << std::endl;
	}
	return out;
}
