/*---------------------------
To test the class functions etc.
*/

#include "cvector.h"


using namespace std;

int main()
{
	cvector v1(2,4,1), v2(1,2,0);
	cvector result;
	//result = v1 - v2;
	//result = v1;
	double coeff = 10.0;
	result = direction(v2,v1);
	result.disp();
	cout<<endl<<abs(result)<<endl;
	return 0;
}