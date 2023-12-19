#include <stdio.h>
#include <omp.h>
int main()
{
	int nb_threads = 20;
	omp_set_num_threads(nb_threads);	

	long long nb_pas = 100000000*20.5;
	long long nb_rect_par_thread = nb_pas / nb_threads;
	double pas = 1./nb_rect_par_thread;
	double Pas = 1./nb_pas;

	double tdebut = omp_get_wtime(); // temps debut

	double Somme = 0;


	#pragma omp parallel
	{
		

		double somme = 0;
		double increment = omp_get_num_threads() * pas;
		#pragma omp for reduction (+:Somme)
		//#pragma omp schedule(dynamic, nb_rect_par_thread)
			for(int i=0; i<nb_pas; i++ )

		{
			somme = somme + 4./(1.+increment*increment);
			increment += pas;
		}
		Somme += somme;
		printf("%f\n", Somme);
		
	}


	Somme = Somme / nb_threads; //nb threads
	double pi = pas * Somme;
	printf("pi = %lf\n", pi);
	double tfin = omp_get_wtime(); // temps fin
	printf("temps d’execution : %lf\n", tfin-tdebut);
}
