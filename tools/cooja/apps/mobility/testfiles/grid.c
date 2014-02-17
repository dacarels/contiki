#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()							
{
	double x_sink=187.5;
	double y_sink=187.5;
	//int node=15;
	int nbr_x_nodes=6;
	int nbr_y_nodes=6;
	double x_begin=0.0;
	double y_begin=0.0;
	double dist = 75.0;
	int node_nr=1;
	double x,y;
	
	FILE *p = NULL;
	char *file = "grid_x-y.dat";
	p = fopen(file, "w+");
	if (p== NULL) {
		printf("Error in opening a file..", file);
	}

	fprintf(p,"#node time(s) x y\n");
	fprintf(p,"0 0.0 %.2f %.2f\n", x_sink, y_sink);
	//fprintf(p,"%d 0.0 0.0 0.0\n", node);

	for(x=x_begin; x <= (x_begin + ((nbr_x_nodes-1)*dist)) ; x=x+dist){
		for(y=y_begin; y <= (y_begin + ((nbr_y_nodes-1)*dist)) ; y=y+dist){
			/*if(
			( (x != x_sink)					||(y != y_sink)) &&
			( (x!=x_begin)					||(y!=y_begin)) &&
			( (x!=x_begin)					||(y!= (y_begin + ((nbr_y_nodes-1)*dist)))) &&
			( (x!= (x_begin + ((nbr_x_nodes-1)*dist)))	||(y!=y_begin)) &&
			( (x!= (x_begin + ((nbr_x_nodes-1)*dist)))	||(y!= (y_begin + ((nbr_y_nodes-1)*dist))))
			) {*/
				fprintf(p,"%d 0.0 %.2f %.2f\n", node_nr, x , y);
				node_nr++;
			//}
		}
	}

	fprintf(p,"0 10000 %.2f %.2f\n", x_sink-0.01, y_sink-0.01);
	
	fclose(p);
}

