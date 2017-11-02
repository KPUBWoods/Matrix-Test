#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <matrix.h>

int main(void)
{
	matrix A(1,2,3,4);
	printf("Matrix A is\n");
	A.print();
	printf("\n");
	printf("Element (0,1) of A is %f\n",A.element(0,1));
	printf("\n");
	matrix B(2);
	printf("Matrix B is\n");
	B.print();
	printf("\n");
	B.multiply(1.5);
	printf("Matrix B times 1.5 is\n");
	B.print();
	matrix C(A.add(B));
	printf("\n");
	printf("Matrix C is Matrix A plus 1.5*(Matrix B)\n");
	C.print();
	printf("\n");
	printf("The determinant of matrix C is %f\n",C.determinant());
	printf("\n");
	matrix D(-5,3,-1,2);
	printf("Matrix D is\n");
	D.print();
	printf("\n");
	C.multiply(D);
	printf("Matrix CD is\n");
	C.print();
	printf("\n");
	C.inverse();
	printf("The inverse of Matrix CD is\n");
	C.print();
	printf("\n");
	matrix E;
	printf("The zero matrix is\n");
	E.print();
}
