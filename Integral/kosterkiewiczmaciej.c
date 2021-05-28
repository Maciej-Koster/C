#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define lp 1000;

double c_od,c_do;

double f3(double x)
{
	double y;
	y=x*sin(x);
	return y;       
} 
     
double f4(double x) 
{
	double y;
	y=x*cos(x);
	return y; 
}

double prostokaty(double( *f)(double))
{
   double krok, p, suma=0;
   krok=(c_do-c_od)/lp;
   for(p=((c_od+c_od+krok)/2); p<c_do; p+=krok)
      suma+=(*f)(p);
	suma *= krok;
   return suma;      
}


double trapezy(double (*f)(double))
{
	double krok, p, suma=0;
	krok=(c_do-c_od)/lp;
	for(p=(c_od+krok); p<c_do; p+=krok)
		suma+= (*f)(p);
	suma = (suma+(((*f)(c_do))+((*f)(c_od))/2))*krok;
	return suma	;
}
 
double mc(double(*f)(double))
{
	double krok, i, suma=0, N = lp;
	srand(time(NULL));
	krok=(c_do-c_od);
	for(i = 1; i <= N; i++)
		suma += (*f)(c_od+((double)rand()/(double)(RAND_MAX+1)*krok));
	suma = krok * suma / N;
}


