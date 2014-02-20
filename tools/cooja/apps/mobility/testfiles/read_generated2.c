#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>

int random_number(int min_num, int max_num);

main()							
{
	double speed=5.0;
	char *file = "random_square_7x7_75m-5km-4u_1.dat";
	std::string inp="destination-4u_1.txt";
	
	double x=450.0;
	double y=450.0;
	double seconde=0.0;
	int node=41;
	
	//double step_dist=5.0/18; //20km/u
	//double step_dist=5.0/24; //15km/u
	//double step_dist=5.0/36; //10km/u
	//double step_dist=5.0/72; //5km/u
	double step_dist=speed/72;
	double step_time=0.05;
	
	//double step_dist=0.275;
	//double step_dist=1.0;
	//double step_time=0.05;	//20km/u
	//double step_time=0.066; //15km/u
	//double step_time=0.1;	//9.9km/u
	//double step_time=0.2;	//4.95km/u
	double x_dest=0.0;
	double y_dest=0.0;
	double distance=1.0;
	double distance2=0.0;
	double prev_dist=10000.0;
	double total_distance=1.0;
	int step=0;
	double x_begin=0.0;
	double y_begin=0.0;	
	double x_dest2=0.0;
	double y_dest2=0.0;
	double distance_n=0.0;
	double total_distance_n=1.0;
	
	FILE *p = NULL;
	//FILE *input=NULL;
	//char *file2 = "destination-6667m.txt";
	
	p = fopen(file, "w+");
	if (p== NULL) {
		printf("Error in opening a file..", file);
	}	
	
	std::ifstream in(inp.c_str());
	if (!in.eof()){
	  in >> x_begin >> y_begin >> distance >> total_distance;
	  printf("New destination x=%.2f y=%.2f dist=%.3f total_dist=%.3f\n", x_begin, y_begin, distance, total_distance);
	}
	
	/*while(!in.eof()){
	  in  >> x_dest >> y_dest >> distance >> total_distance;
	  printf("New destination x=%.2f y=%.2f dist=%.3f total_dist=%.3f\n", x_dest, y_dest, distance, total_distance);
	}*/

	fprintf(p,"#node time(s) x y\n");
	fprintf(p,"%d 0.0 %.2f %.2f\n", node, x , y); //mobile node
	
	//srand ( time(NULL) );

	seconde+=120;
	in  >> x_dest >> y_dest >> distance >> total_distance;
	printf("New destination x=%.2f y=%.2f dist=%.3f total_dist=%.3f\n", x_dest, y_dest, distance, total_distance);
	//in  >> x_dest2 >> y_dest2 >> distance_n >> total_distance_n;
	//printf("New destination x=%.2f y=%.2f dist=%.3f total_dist=%.3f\n", x_dest2, y_dest2, distance_n, total_distance_n);
	while(!in.eof()){
	  distance2= fabs(sqrt(pow((x_dest-x),2)+pow((y_dest-y),2)));
	  //printf("Distance is %.2f\n", distance);
	  if(prev_dist < distance2){
	  //if(step_dist > distance2){
	    /*printf("Voor:%d %.3f %.2f %.2f\n", node, seconde, x, y);
	    x_dest=((double)random_number(0,45000))/100;
	    y_dest=((double)random_number(0,45000))/100;
	    printf("New destination x:%.2f and y:%.2f with time:%.2f\n",x_dest,y_dest, seconde);
	    printf("Na:%d %.3f %.2f %.2f\n", node, seconde, x, y);*/
	    x_begin=x_dest;
	    y_begin=y_dest;
	    x=x_dest;
	    y=y_dest;
	    fprintf(p,"%d %.3f %.2f %.2f\n", node, seconde, x, y);
	    seconde+=step_time;
	    step=1;
	    prev_dist=10000.0;
	    //x_dest=x_dest2;
	    //y_dest=y_dest2;
	    //distance=distance_n;
	    //total_distance=total_distance_n;
	    in  >> x_dest >> y_dest >> distance >> total_distance;
	    if (x_begin!=x_dest && y_begin!=y_dest)
	      printf("New destination x=%.2f y=%.2f dist=%.3f total_dist=%.3f on time=%.2f seconds\n", x_dest, y_dest, distance, total_distance, seconde);
	    else
	      break;
	    //distance= fabs(sqrt(pow((x_dest-x),2)+pow((y_dest-y),2)));
	  } else {
	    prev_dist=distance2;
	  }
	  x= ((step_dist * step * (x_dest-x_begin))/distance)+x_begin;
	  y= ((step_dist * step * (y_dest-y_begin))/distance)+y_begin;
	  //fprintf(p,"%d %.3f %.2f %.2f %.2f\n", node, seconde, x, y,((((step*step_dist)+total_distance-distance)*3600)/(1000*(seconde-120)));
	  fprintf(p,"%d %.3f %.2f %.2f\n", node, seconde, x, y);
	  //fprintf(p,"%d %.3f %.2f %.2f %.2f dist=%.2f\n", node, seconde, x, y,((((step*step_dist)+total_distance-distance)*3600)/(1000*(seconde-120))), distance2);
	  seconde+=step_time;
	  step++;
	}
	fprintf(p,"%d %.3f %.2f %.2f\n", node, seconde+1000, x+0.01, y+0.01);
	
	
	fclose(p);
	in.close();
}

/*int random_number(int min_num, int max_num){
  int result=0,low_num=0,hi_num=0;
  if(min_num<max_num){
    low_num=min_num;
    hi_num=max_num+1; // this is done to include max_num in output.
  }else{
    low_num=max_num+1;// this is done to include max_num in output.
    hi_num=min_num;
  }
  //srand(time(NULL));
  result = (rand()%(hi_num-low_num))+low_num;
  return result;
}
*/