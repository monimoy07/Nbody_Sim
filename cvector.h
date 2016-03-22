/*----------------------------------------
A class that defines a type to 
contain cartesian coordinates

TESTED

------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <cmath> //For sqrt

class cvector
{
	public:
	double x1,x2,x3;

	cvector(){} //constructor

	//copy constructor
	cvector(double a1,double a2,double a3)
	{
		x1 = a1;
		x2 = a2;
		x3 = a3;
	}

	//Display Vector
	void disp()
	{
		std::cout<<"("<<x1<<","<<x2<<","<<x3<<")";
	}

	/* 
	Following stuff overload the traditional operators
	to also allow for vector addition, subtraction, 
	scalar multiplication/division and dot product
	*/
	cvector operator + (const cvector&);
	cvector operator - (const cvector&);
	double operator * (const cvector&); //dot product

};

//vector addtion
cvector cvector::operator + (const cvector& param)
{
	cvector temp;
	temp.x1 = x1 + param.x1;
	temp.x2 = x2 + param.x2;
	temp.x3 = x3 + param.x3;
	return temp;
}

//vector subtraction
cvector cvector::operator - (const cvector& param)
{
	cvector temp;
	temp.x1 = x1 - param.x1;
	temp.x2 = x2 - param.x2;
	temp.x3 = x3 - param.x3;
	return temp;
}

//Dot Product
double cvector::operator * (const cvector& param)
{
	return (x1*param.x1 + x2*param.x2 + x3*param.x3);
}

//Scalar float/double Multiplication on a vector
cvector operator * (double lhs, cvector rhs)
{
	 cvector temp;
	 temp.x1 = lhs*rhs.x1;
	 temp.x2 = lhs*rhs.x2;
	 temp.x3 = lhs*rhs.x3;
	 return temp;
}

//Scalar int Multiplication on a vector
cvector operator * (int lhs, cvector rhs)
{
	 cvector temp;
	 temp.x1 = lhs*rhs.x1;
	 temp.x2 = lhs*rhs.x2;
	 temp.x3 = lhs*rhs.x3;
	 return temp;
}

//Scalar division on a vector
cvector operator / (cvector lhs, double rhs)
{
	 cvector temp;
	 temp.x1 = lhs.x1/rhs;
	 temp.x2 = lhs.x2/rhs;
	 temp.x3 = lhs.x3/rhs;
	 return temp;
}

//Scalar division on a vector
cvector operator / (cvector lhs, int rhs)
{
	 cvector temp;
	 temp.x1 = lhs.x1/rhs;
	 temp.x2 = lhs.x2/rhs;
	 temp.x3 = lhs.x3/rhs;
	 return temp;
}

//Magnitude of the vector
double abs(cvector v)
{
	return (sqrt(v*v)); //Magnitude of a vector
}

//Distance between v1 and v2
double distance(cvector v1, cvector v2)
{
	return (abs(v2 - v1));
}

//Unit vector from b1 to b2
cvector direction(cvector b1, cvector b2)
{
	return (b2 - b1)/(abs(b2 - b1)); 
}
