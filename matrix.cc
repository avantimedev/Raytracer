/*
 * =====================================================================================
 *
 *       Filename:  matrix.cc
 *
 *    Description:  
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

Matrix Matrix::inverse() {
	// TODO: Implement this!
	Matrix m;
	return m;
}

void Matrix::zero() {
	for (int i=0;i<16;i++)
			elems[i] = 0;
}

double Matrix::getXY(int x, int y) {
	return elems[y + x*4];
}

void Matrix::setXY(int x, int y, double value) {
	elems[y + x*4] = value;
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

