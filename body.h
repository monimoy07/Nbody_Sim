/*----------------------------------------------

A class and the functions on the celestial body

WARNING : UNTESTED AND INCOMPLETE!

-----------------------------------*/

#include "cvector.h"
#define G_CONST 6.67408e-11

class body
{
	public:

	int idx; //Index of the body
	double mass; //Mass of the body
	cvector position; //position of the body
	cvector velocity; //velocity of the body
	cvector acceleration; //accelaration of the body

	static int No_obj; //Number of bodies (objects of class body) created

	cvector(){++No_obj;} //Constructor

	cvector(double mass0, cvector pos0, cvector vel0)
	{
		mass = mass0;
		pos = pos0;
		vel = vel0; 
	}

};

int body::No_obj=0;

cvector direction(body b1, body b2)
{
	return (b2.position - b1.position)/(abs(b2.position - b1.position)); 
}

double distance(body b1, body b2)
{
	return (abs(b2.position - b1.position));
}

/*
N is number of bodies passed into this function
No_obj (which is the total no. of objects created) 
can be different from N

The acceleration is calculated by summing up contributions
by the rest of the bodies.

This portion would require parallelization.
*/
void calculate_acc(body bodies[], int N) 
{
	int i,j;
	cvector acc(0,0,0);
	double coeff = 0;
	for (i = 0; i<N; i++)
	{
		for (j= 0; j<N;j++)
		{
			if(j != i)
			{
			coeff = (G_CONST*bodies[j].mass)/(distance(bodies[i].position,bodies[j].position)*distance(bodies[i].position,bodies[j].position));
			bodies[i].acceleration = bodies[i].acceleration + coeff*(direction(bodies[i].position,bodies[j].position)); 		
			}	
		}	
		
	}
}