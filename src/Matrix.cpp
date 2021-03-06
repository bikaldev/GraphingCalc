#include "Matrix.hpp"

void Matrix::setElement(int a, int b, double val)
{
	if (m < a || n < b)
		throw OUTOFRANGE(m, n, a, b);
	this->el[a * this->n + b] = val;
}

void Matrix::operator()(std::vector<double> mat)
{
	for (int i = 0; i < static_cast<int>(mat.size()); i++)
	{
		el[i] = mat.at(i);
	}
}

void Matrix::operator()(std::initializer_list<double> args)
{
	int j = 0;
	for (double i : args)
	{
		el[j] = i;
		j++;
	}
}

void Matrix::operator()(const double* a)
{
	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			el[this->n * i + j] = a[this->n * i + j];
		}
	}
}

// ostream& Matrix::operator<<(ostream& os)
// {
// 	os << "[";
// 	for (int i = 0; i < this->m; i++)
// 	{
// 		for (int j = 0; j < this->n; j++)
// 		{
// 			os << " " << this->el[this->n * i + j] << "  ";
// 		}
// 		(i == m - 1) ? os << "]" : os << std::endl;
// 	}
// 	os << std::endl;
// 	return os;
// }

double Matrix::operator()(int m_row, int n_col)
{
	if (m_row < this->m and n_col < this->n)
	{
		int pos = this->n * m_row + n_col;
		return *(this->el + pos);
	}
	else
	{
		throw OUTOFRANGE(this->m, this->n, m_row, n_col);
	}
}

Matrix Matrix::operator+(Matrix m2)
{
	Matrix m3(this->m, this->n);
	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			m3.el[this->n * i + j] = (*this)(i, j) + m2(i, j);
		}
	}
	return m3;
}

Matrix Matrix::operator-(Matrix m2)
{
	Matrix m3(this->m, this->n);
	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			m3.el[this->n * i + j] = (*this)(i, j) - m2(i, j);
		}
	}
	return m3;
}

Matrix Matrix::operator*(Matrix m2)
{
	if (this->n != m2.m)
		throw ORDEREXCEPTION(this->m, this->n, m2.m, m2.n);
	Matrix m3(this->m, m2.n);
	double dot;
	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < m2.n; j++)
		{
			dot = 0.0;
			for (int k = 0; k < m2.m; k++)
			{
				dot += this->el[this->n * i + k] * m2(k, j);
			}
			m3.el[m2.n * i + j] = dot;
		}
	}
	return m3;
}

Matrix Matrix::operator*(double k)
{
	Matrix m1(this->m, this->n);
	for (int i = 0; i < this->m * this->n; i++)
	{
		m1.el[i] = this->el[i] * k;
	}
	return m1;
}

Matrix Matrix::operator/(double k)
{
	if (k == 0)
		throw DIVIDEBYZERO();
	Matrix m1(this->m, this->n);
	for (int i = 0; i < this->m * this->n; i++)
	{
		m1.el[i] = this->el[i] / k;
	}
	return m1;
}

double Matrix::minor(int a, int b)
{
	Matrix sub(this->m - 1, this->n - 1);
	int i = 0, k = 0;
	while (i < this->m)
	{
		if (i == a)
		{
			i++;
			continue;
		}
		int j = 0, l = 0;
		while (j < this->n)
		{
			if (j == b)
			{
				j++;
				continue;
			}
			sub.setElement(k, l, (*this)(i, j));
			j++;
			l++;
		}
		i++;
		k++;
	}
	return det(sub);
}

double Matrix::coFactor(int a, int b)
{
	return pow(-1, a + b) * this->minor(a, b);
}

double Matrix::det(Matrix m)
{
	if (m.row() == 1 && m.column() == 1)
	{
		return m(0, 0);
	}
	double sum = 0.0;
	for (int i = 0; i < m.column(); i++)
	{
		sum += m(0, i) * m.coFactor(0, i);
	}
	return sum;
}

Matrix Matrix::trans(Matrix m1)
{
	Matrix m2(m1.n, m1.m);
	for (int i = 0; i < m1.m; i++)
	{
		for (int j = 0; j < m1.n; j++)
		{
			m2.setElement(j, i, m1(i, j));
		}
	}
	return m2;
}

Matrix Matrix::inv(Matrix m1)
{
	double d = det(m1);
	if (d == 0)
		throw SINGULAREXCEPTION();
	Matrix inv_m(m1.m, m1.n);
	for (int i = 0; i < m1.m; i++)
	{
		for (int j = 0; j < m1.n; j++)
		{
			inv_m.setElement(i, j, m1.coFactor(j, i));
		}
	}
	return inv_m / d;
}
