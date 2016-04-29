#define N 625
#define mass 5e24

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main(){
	ofstream of;
	of.open("body_data.txt",ios::out);
	double sq = 5e12;
	int i,j,idx=0;
	
	of<<ceil(sqrt(N))*ceil(sqrt(N))<<"\n";
	for(i=0;i<sqrt(N);i++){
		for(j=0;j<sqrt(N);j++){
			of<<idx++<<"\t"<<mass<<"\t"<<i*sq/sqrt(N)<<"\t"<<j*sq/sqrt(N)<<"\t"<<0.0<<"\t" \
			<<0.0<<"\t"<<0.0<<"\t"<<0.0<<"\n";
		}	
	}	
	return 0;
}