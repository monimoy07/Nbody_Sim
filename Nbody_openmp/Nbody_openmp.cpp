/*------------------------------------------

Serial code to simulate the movement of N bodies
in space.

What to do with collisions?

---------------------------------------------*/



#define DT 1e5
#define FINAL_TIME 1e8
#define WRITE_DT 1e6
#define G_CONST 6.67408e-11
//#define SOLN_FOLDER "soln1"

#include <omp.h>

#include "body.h"
#include "rk4.h"

#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

 

using namespace std;

int main()
{
	ifstream input_file;
	ofstream output_file;
	
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
	
	cout << "\n";
  cout << "Nbody_openmp\n";
  cout << "  C++/OpenMP version\n";

  cout << "\n";
  cout << "  Number of processors available = " << omp_get_num_procs ( ) << "\n";
  cout << "  Number of threads =              " << omp_get_max_threads ( ) << "\n";
	
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
	input_file.close(); //Closing the input file
	
	calculate_acc(bods,N);
	std::ostringstream strs;
	strs << 0;
	std::string file_name = strs.str();
	
	//****Writing data for 0 time
	output_file.open(file_name.c_str(), ios::out);
	if(!output_file.is_open())
	{
		cout<<"\n\nFile 0 could not be opened, Error in opening! Exiting.\n\n";
		return 1;
	}
	
	//Writing the number of bodies
	output_file<<N<<"\n"; 
	
	
	//Writing the body parameters into textfile 
	for(i = 0; i<N; i++)
	{
		output_file<<bods[i].idx<<"\t"<<bods[i].mass<<"\t" \
		<<bods[i].position.x1<<"\t";
		output_file<<bods[i].position.x2<<"\t";
		output_file<<bods[i].position.x3<<"\t";
		output_file<<bods[i].velocity.x1<<"\t";
		output_file<<bods[i].velocity.x2<<"\t";
		output_file<<bods[i].velocity.x3<<"\t";
		output_file<<bods[i].acceleration.x1<<"\t";
		output_file<<bods[i].acceleration.x2<<"\t";
		output_file<<bods[i].acceleration.x3<<"\n";
		
	}
	
	output_file.close(); //Closing the output file
	/*****/
	
	double dt = DT;
	double t = 0.0;
	int no_write = 1;
	double write_t = WRITE_DT*no_write;
	cout<<"\n\nRunning simulation for "<<N<<" bodies...";
	cout<<"\n\n dt = "<<dt;
	cout<<"\n\n write dt = "<<WRITE_DT;
	/********************
	Main Loop
	*********************/
	while (t < FINAL_TIME)
	{
		rk4(bods,N,dt);
		t = t+dt;
		
		//Writing the data to input file for t+dt time
		
		if(t == write_t )
		{
			strs.str("");
			strs.clear();
			strs << write_t;
			file_name = strs.str();
	
			//****Writing data for write_t time
			cout<<"\n\nWriting data for time "<<write_t<<" ....";
			output_file.open(file_name.c_str(), ios::out);
			if(!output_file.is_open())
			{
				cout<<"\n\nFile "<<file_name.c_str()<<" could not be opened, Error in opening! Exiting.\n\n";
				return 1;
			}
	
			//Writing the number of bodies
			output_file<<N<<"\n"; 
	
	
			//Writing the body parameters into textfile 
			for(i = 0; i<N; i++)
			{
				output_file<<bods[i].idx<<"\t"<<bods[i].mass<<"\t" \
				<<bods[i].position.x1<<"\t";
				output_file<<bods[i].position.x2<<"\t";
				output_file<<bods[i].position.x3<<"\t";
				output_file<<bods[i].velocity.x1<<"\t";
				output_file<<bods[i].velocity.x2<<"\t";
				output_file<<bods[i].velocity.x3<<"\t";
				output_file<<bods[i].acceleration.x1<<"\t";
				output_file<<bods[i].acceleration.x2<<"\t";
				output_file<<bods[i].acceleration.x3<<"\n";
		
			}
	
			output_file.close(); //Closing the output file
			/*****/
			
			
			//Next write time-step
			no_write++;
			write_t = WRITE_DT*no_write;
		}//End of writing
	}//End of main loop
	
	cout<<endl<<"Final Body Parameters ..... "<<endl<<endl;
	for(i = 0; i<N ; i++)
	{
		
		bods[i].disp_params(); cout<<endl<<endl;	
	}
	
	delete [] bods; //Delete Memory from heap
	
	return 0;
}
