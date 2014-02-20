#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()							
{
	double x=600.0;
	double y=200.0;
	double seconde=0.0;
	int node=0;
	
	FILE *p = NULL;
	char *file = "horizon200left_20km.dat";
	p = fopen(file, "w+");
	if (p== NULL) {
		printf("Error in opening a file..", file);
	}

	printf("#node time(s) x y\n");
	fprintf(p,"#node time(s) x y\n");
	//fprintf(p,"0 0.0 210.0 100.0\n");
	fprintf(p,"1 0.0 0.0 0.0\n");


	fprintf(p,"%d 0.0 %.2f %.2f\n", node, x , y); //mobile node



	seconde+=60;
	while(x>0){
		x=x-0.275;
		seconde=seconde+0.05; //20km/u
		//seconde=seconde+0.066; //15km/u
		//seconde=seconde+0.1;	//9.9km/u
		//seconde=seconde+0.2;	//4.95km/u
		fprintf(p,"%d %.1f %.2f %.2f\n", node, seconde, x, y);
	}
	seconde+=60;
	while(x<600){
		x=x+0.275;
		seconde=seconde+0.05; //20km/u
		//seconde=seconde+0.066; //15km/u
		//seconde=seconde+0.1;	//9.9km/u
		//seconde=seconde+0.2;	//4.95km/u
		fprintf(p,"%d %.1f %.2f %.2f\n", node, seconde, x, y);
	}
	for(; seconde<3000.0; seconde=seconde+10){
		fprintf(p,"%d %.1f %.2f %.2f\n", node, seconde, x,y);
	}
	fclose(p);
}

