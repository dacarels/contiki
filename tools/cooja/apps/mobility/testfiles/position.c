#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()							
{
	double x=10.0;
	double y=300.0;
	double seconde=0.0;
	int node=5;
	
	FILE *p = NULL;
	char *file = "horizontal_5.dat";
	p = fopen(file, "w+");
	if (p== NULL) {
		printf("Error in opening a file..", file);
	}

	printf("#node time(s) x y\n");
	fprintf(p,"#node time(s) x y\n");
	fprintf(p,"0 0.0 210.0 100.0\n");
	fprintf(p,"1 0.0 160.0 170.0\n");
	fprintf(p,"2 0.0 260.0 170.0\n");
	fprintf(p,"3 0.0 140.0 240.0\n");
	fprintf(p,"4 0.0 280.0 240.0\n");
	//fprintf(p,"5 0.0 290.0 300.0\n");
	//fprintf(p,"6 0.0 150.0 220.0\n");
	//fprintf(p,"7 0.0 90.0 260.0\n");
	//fprintf(p,"8 0.0 160.0 260.0\n");
	//fprintf(p,"9 0.0 80.0 180.0\n");
	//fprintf(p,"10 0.0 80.0 190.0\n");
	//fprintf(p,"11 0.0 70.0 230.0\n");
	//fprintf(p,"12 0.0 80.0 230.0\n");
	//fprintf(p,"13 0.0 105.0 250.0\n");
	//fprintf(p,"14 0.0 140.0 250.0\n");


	fprintf(p,"%d 0.0 %.2f %.2f\n", node, x , y); //mobile node


/*
	for(x=0; x<30.0; x=x+0.05){
		seconde=seconde+0.2;
		fprintf(p,"%d %.1f %.2f 140.0\n", node, seconde, x);
	}
	for(; x<56.0; x=x+0.05){
		seconde=seconde+0.2;
		y=y-0.05;
		fprintf(p,"%d %.1f %.2f %.2f\n", node, seconde, x, y);
	}
*/
	seconde+=80;
	while(x<320){
		x=x+0.275;
		//seconde=seconde+0.05; //20km/u
		//seconde=seconde+0.066; //15km/u
		//seconde=seconde+0.1;	//9.9km/u
		seconde=seconde+0.2;	//4.95km/u
		fprintf(p,"%d %.1f %.2f %.2f\n", node, seconde, x, y);
	}
	for(; seconde<2000.0; seconde=seconde+10){
		fprintf(p,"%d %.1f %.2f %.2f\n", node, seconde, x,y);
	}
	fclose(p);
}
