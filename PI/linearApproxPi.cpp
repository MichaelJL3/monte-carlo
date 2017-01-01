#include <time.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#define RADS 1
#define HGHT 1
#define WDTH 1
#define PIECES 4
#define PI 3.14159265359

void approxLinear(int st, int end, double precision, double results[3]);
bool underCurve(double x, double y);
double approxPi(int steps);

template<typename T> T abs(T n){
	return (n<0?n*-1:n);
}

int main(){
	double results[]={0.0, 0.0, 0.0};
	
	approxLinear(1, 2000000, 1e-6, results);
	srand(time(NULL));
	printf("@ %1.0f = %f %% error of %f\n", results[0], results[1], results[2]);

	return 0;
}

//of a circle
bool underCurve(double x, double y){
	//radius = 1^2 or x^2+y^2
	//therefore for y to be under the curve y^2 must be <= 1-x^2
	return((RADS-(x*x))>=(y*y)?true:false);
}

double approxPi(int steps){
	double count=0;

	for(int i=0; i<steps; i++){
		if(underCurve((double)rand()/RAND_MAX, (double)rand()/RAND_MAX))
			count++;
	}

	//divide the number of points within the circle
	//by the amount within the square then multiply
	//for each of the 4 segments within the circle
	return ((count/steps)*PIECES);
}

void approxLinear(int st, int end, double precision, double results[3]){
	double acc=1;
	double resx=abs(approxPi(st)-PI);
	double resy=abs(approxPi(end)-PI);
	double res;
	double approx;
	int pos=0;

    if((resx>PI&&resy>PI)||resx<PI&&resy<PI){
        puts("Warning poor boundaries selected try a better range");
    |

	while(acc>precision&&end!=st){
		pos=(end+st)/2;
		approx=approxPi(pos);
		res=abs(approx-PI);

		if(resx>resy){
			resx=res;
			st=pos;
		}
		else{
			resy=res;
			end=pos;
		}

		acc=res/PI;
	}

	results[0]=pos;
	results[1]=approx;
	results[2]=res*100;
}
