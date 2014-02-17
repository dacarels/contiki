#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int random_number(int min_num, int max_num);

main()							
{
	double x=450.0;
	double y=450.0;
	double seconde=0.0;
	int node=41;
	double step_dist=0.275;
	//double step_dist=1.0;
	//double step_time=0.05;	//20km/u
	//double step_time=0.066; //15km/u
	//double step_time=0.1;	//9.9km/u
	double step_time=0.2;	//4.95km/u
	double x_dest=0.0;
	double y_dest=0.0;
	double distance=0.0;
	
	FILE *p = NULL;
	char *file = "random_square_7x7_75m-5km.dat";
	p = fopen(file, "w+");
	if (p== NULL) {
		printf("Error in opening a file..", file);
	}

	fprintf(p,"#node time(s) x y\n");
	fprintf(p,"%d 0.0 %.2f %.2f\n", node, x , y); //mobile node

	srand ( time(NULL) );

	seconde+=120;
	x_dest=((double)random_number(0,45000))/100;
	y_dest=((double)random_number(0,45000))/100;
	printf("New destination x:%.2f and y:%.2f\n",x_dest,y_dest);
	while(seconde<3000.0){
	  distance= fabs(sqrt(pow((x_dest-x),2)+pow((y_dest-y),2)));
	  //printf("Distance is %.2f\n", distance);
	  if(step_dist > distance){
	    printf("Voor:%d %.3f %.2f %.2f\n", node, seconde, x, y);
	    x_dest=((double)random_number(0,45000))/100;
	    y_dest=((double)random_number(0,45000))/100;
	    printf("New destination x:%.2f and y:%.2f with time:%.2f\n",x_dest,y_dest, seconde);
	    printf("Na:%d %.3f %.2f %.2f\n", node, seconde, x, y);
	    distance= fabs(sqrt(pow((x_dest-x),2)+pow((y_dest-y),2)));
	  }
	  x+= (step_dist * (x_dest-x))/distance;
	  y+= (step_dist * (y_dest-y))/distance;
	  fprintf(p,"%d %.3f %.2f %.2f\n", node, seconde, x, y);
	  seconde+=step_time;
	}
	
	fclose(p);
}

int random_number(int min_num, int max_num){
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

