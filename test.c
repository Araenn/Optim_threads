#include <stdio.h>
#include <omp.h>
int main()
{
	long long nb_pas = 1000;
	double pas = 1./nb_pas;
	double tdebut = omp_get_wtime(); // temps debut
	double somme = 0;
	for(int i=0; i<nb_pas; i++)
	{
		double x = (i+.5)*pas;
		somme = somme + 4./(1.+x*x);
	}

	double pi = pas * somme;
	printf("pi = %lf\n", pi);
	double tfin = omp_get_wtime(); // temps fin
	printf("temps d’execution : %lf\n", tfin-tdebut);
}
