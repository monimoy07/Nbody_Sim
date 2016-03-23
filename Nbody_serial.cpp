/*------------------------------------------

Serial code to simulate the movement of N bodies
in space.

What to do with collisions?

---------------------------------------------*/




#include "body.h"
#include <stdio.h>
#include <fstream>
#include <string>


using namespace std;

int main()
{
	ifstream input_file;
	
	input_file.open("body_data.txt", ios::in);
	if(!input_file.is_open())
	{
		cout<<"\n\nFile not found or Error in opening! Exiting.\n\n";
		return 1;
	}
	
	
	/*-----------------------------------------
	
	Text File Format  :
	1. <No. of Bodies>
	2.	<Index of Body 1> <Mass of Body 1> <Pos of Body 1> <vel of Body 1>
	3.	<Same for body 2 and so on>
	
	Example :
	2
	0	2e10	1 0 0	0 5 0		
	1	2e10	0 -1 0	0 -5 0
	---------------------------------------*/
	
	//Reading the no. of bodies from the text file
	int i;
	input_file>>i;
	const int N = i;
	
	cout<<"\n\n No of Bodies = "<<N<<"\n\n"; //Display N
	
	//Creating the body array in the heap
	body *bods = new body[N];
	
	//Reading the data into the array
	for(i = 0; i<N; i++)
	{
		input_file>>bods[i].idx>>bods[i].mass;
		input_file>>bods[i].position.x1;
		input_file>>bods[i].position.x2;
		input_file>>bods[i].position.x3;
		input_file>>bods[i].velocity.x1;
		input_file>>bods[i].velocity.x2;
		input_file>>bods[i].velocity.x3;
		
		//Display Body Parameters
		//bods[i].disp_params(); cout<<endl<<endl;
	}

	calculate_acc(bods,N);

	for(i = 0; i<N ; i++)
	{
		bods[i].disp_params(); cout<<endl<<endl;	
	}
	
	delete [] bods; //Delete Memory from heap
	
	return 0;
}
