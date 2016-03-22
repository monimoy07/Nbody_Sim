/*---------------------------
To test the class functions etc.
*/

#include "body.h"


using namespace std;

int main()
{
	cvector p1(1,0,0), p2(-1,0,0);
	cvector v1(0,1,0), v2(0,-1,0);
	cvector result;
	//result = v1 - v2;
	//result = v1;
	double coeff = 10.0;
	body bods[2];
	bods[0].mass = 2e30;
	bods[0].position = p1;
	bods[0].velocity = v1;
	bods[1].mass = 5.9e24;
	bods[1].position = p2;
	bods[1].velocity = v2;
	
	result = direction(bods[0],bods[1]);
	cout<<"\n\n Direction of Body 2 from Body 1 : ";
	result.disp();
	//cout<<"\n\n"<<abs(result)<<endl<<endl;

	calculate_acc(bods,body::No_obj);
	
	bods[0].disp_params();
	cout<<"\n\n";
	bods[1].disp_params();
	
	return 0;
}