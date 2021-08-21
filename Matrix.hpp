#pragma once
#include "MatrixException.hpp"
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <vector>

class Matrix
{
private:
	double* el;
	int m, n;

	friend Matrix trans(Matrix);
	friend Matrix inv(Matrix);
	friend double det(Matrix);

public:
	Matrix() = default;
	Matrix(int m, int n)
	{
		this->m = m;
		this->n = n;
		el = new double[m * n];
	}

	Matrix operator+(Matrix m2);
	Matrix operator*(Matrix m2);
	Matrix operator*(double);
	Matrix operator-(Matrix m2);
	Matrix operator/(double);

	// ostream& operator<<(ostream& os);

	virtual double operator()(int m_row, int n_col);
	void operator()(std::initializer_list<double> args);
	void operator()(const double*);
	void operator()(std::vector<double> mat);

	void setElement(int a, int b, double val);

	int row() const
	{
		return m;
	};

	int column() const
	{
		return n;
	};

	double minor(int a, int b);
	double coFactor(int a, int b);

	//static member functions:
public:
	static double det(Matrix m);
	static Matrix trans(Matrix m1);
	static Matrix inv(Matrix m1);
};
