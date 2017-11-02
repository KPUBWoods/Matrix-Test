#include <matrix.h>
#include <stdlib.h>
#include <stdio.h>

matrix::matrix()
{
	/*
		This constructor (the default constructor) creates a matrix with all zero elements
	*/

	e00 = 0;
	e01 = 0;
	e10 = 0;
	e11 = 0;
}

matrix::matrix(double a)
{
	/*
		This constructor should create a diagonal matrix with the diagonal elements equal to a and
		the other elements equal to zero.

		TO DO
	*/
	e00 = e11 = a;
	e01 = e10 = 0;
}

matrix::matrix(double a, double b, double c, double d)
{
	/*
		This constructor should set the elements the values of the elements using the
		parameters a,b,c,d

		TO DO
	*/
	e00 = a;
	e01 = b;
	e10 = c;
	e11 = d;
}

matrix::matrix(const matrix& a)
{
	/*
		This is the copy constructor: it takes a matrix and makes a new one with the same element values
	*/

	e00 = a.e00;
	e01 = a.e01;
	e10 = a.e10;
	e11 = a.e11;
}

matrix& matrix::add(matrix& a)
{
	/*
		The add member function adds the elements of matrix 'a' to this matrix. 
	*/

	e00 = e00 + a.e00;
	e01 = e01 + a.e01;
	e10 = e10 + a.e10;
	e11 = e11 + a.e11;

	return *this;
}

matrix& matrix::multiply(double x)  // TO DO: Multiply the matrix by a scalar
{
	e00=e00*x;
	e10=e10*x;
	e01=e01*x;
	e11=e11*x;
}
	
matrix& matrix::multiply(matrix& m)  // TO DO: Multiply the matrix by another matrix
{
	e00 = (e00 * m.e00 + e01 * m.e10);
	e01 = (e00 * m.e01 + e01 * m.e11);
	e10 = (e10 * m.e00 + e11 * m.e10);
	e11 = (e10 * m.e01 + e11 * m.e11);
}

double matrix::element(int column,int row) // TO DO: return the specified element using its column and row number
{
	if (column == 0)
	{
		if (row == 0)
		{
			return e00;
		}
		if (row == 1)
		{
			return e10;
		}
	}
	if (column == 1)
	{
		if (row == 0)
		{
			return e01;
		}
		if (row == 1)
		{
			return e11;
		}
	}
}

double matrix::determinant() // TO DO: return the determinant of the matrix
{
	float ans;
	ans = e00*e11-e01*e10;
	return ans;
}

matrix& matrix::inverse() // TO DO: return the inverse of the matrixs
{
	float det;
	float temp;
	det = determinant();
	temp = e00;
	e00 = e11/det;
	e11 = temp/det;
	temp = 0;
	e10 = (0-e10)/det;
	e01 = (0-e01)/det;
}

void matrix::print() // TO DO: a function to print out the matrix to the console.}
{
	printf("| %f, %f |\n", e00, e01);
	printf("| %f, %f |\n", e10, e11);
}