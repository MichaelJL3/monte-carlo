#include "pi.h"

int main(int argv, char** argc){
	double x=0;
	double y=0;
	int circle=0;
	int num_points;

	srand(time(NULL));

	if(argv<2){
		printf("Enter number of options: \n>");
		scanf("%d", &num_points);
	}else{
		num_points=atoi(argc[1]);
	}

	for(int i=0; i<num_points; i++){
		x=((double)rand())/RAND_MAX;
		y=((double)rand())/RAND_MAX;
		if(computeCircle(x)>=y)
			circle++;
	}

	printf("PI approximation: %f\n", (((double)circle/num_points)*4));

	return 0;
}

double computeCircle(double x){
	return sqrt(1-x*x);
}