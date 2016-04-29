// File for RK-4 Integration

void rk4(body bodies[], int N, double dt)

{ 
 int i;
 
 body *bodies1 = new body[N];
 body *bodies2 = new body[N];
 body *bodies3 = new body[N];
 
 
 copy_body(bodies1,bodies, N);
 copy_body(bodies2,bodies, N);
 copy_body(bodies3,bodies, N);
 
 /*
 std::cout<<"\n\nBodies parameters : ";
 for(i=0;i<N;i++)
 {
 bodies[i].disp_params();
 }
 */
 
 /*
 std::cout<<"\n\nBodies 1 parameters : ";
 for(i=0;i<N;i++)
 {
 bodies1[i].disp_params();
 }
 */
 
 
 
 for(i=0;i<N;i++)
 	{
 		bodies1[i].position = (bodies[i].position + ((dt*0.5)*bodies[i].velocity));
 		bodies1[i].velocity = (bodies[i].velocity + ((dt*0.5)*bodies[i].acceleration));
 		calculate_acc(bodies1,N);
 	}
/*
std::cout<<"\n\nBodies 1 parameters after first loop : ";
 for(i=0;i<N;i++)
 {
 bodies1[i].disp_params();
 }
*/	

 for(i=0;i<N;i++)
 	{
 		bodies2[i].position = (bodies[i].position + ((dt*0.5)*bodies1[i].velocity));
 		bodies2[i].velocity = (bodies[i].velocity + ((dt*0.5)*bodies1[i].acceleration));
 		calculate_acc(bodies2,N);
 	}
/*
std::cout<<"\n\nBodies 2 parameters after second loop : ";
 for(i=0;i<N;i++)
 {
 bodies2[i].disp_params();
 }
 */


for(i=0;i<N;i++)
 	{
 		bodies3[i].position = (bodies[i].position + (dt*bodies2[i].velocity));
 		bodies3[i].velocity = (bodies[i].velocity + (dt*bodies2[i].acceleration));
 		calculate_acc(bodies3,N);
 	}

/*
std::cout<<"\n\nBodies3 parameters after third loop : ";
 for(i=0;i<N;i++)
 {
 bodies3[i].disp_params();
 }
*/

 	
//Update position & velocity using previous 4 steps
for(i=0;i<N;i++)
	{
		bodies[i].position = (bodies[i].position + ((dt/6.0)*(bodies[i].velocity + (2*bodies1[i].velocity) + (2*bodies2[i].velocity) + bodies3[i].velocity)));
		bodies[i].velocity = (bodies[i].velocity + ((dt/6.0)*(bodies[i].acceleration + (2*bodies1[i].acceleration) + (2*bodies2[i].acceleration) + bodies3[i].acceleration)) );    
		calculate_acc(bodies,N); 	
	/*
	std::cout<<"\n\nbodies position + Sum of velocities * dt/6 = ";
	//cvector l = bodies[i].position + ((dt/6.0)*(bodies[i].velocity + (2*bodies1[i].velocity) + (2*bodies2[i].velocity) + bodies3[i].velocity));
	//l.disp();
	bodies[i].position.disp();
	bodies[i].velocity.disp();
	*/
	}

std::cout<<"\n\nBodies parameters finally at end of rk4 step : ";
 for(i=0;i<N;i++)
 {
 bodies[i].disp_params();
 }


delete [] bodies1;
delete [] bodies2;
delete [] bodies3;
}//End of Rk4