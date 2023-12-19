#include <stdio.h>
#include <omp.h>
int main()
{
int compteur = 0;
int dernierThread = 0;
int nombreThread = 0;
printf("%d seul thread, pas parallele\n", omp_get_num_threads());
printf("thread no. %d\n\n", omp_get_thread_num());
int y;
#pragma omp master
{

printf("Il y a %d thread, le no. : %d\n\n", omp_get_num_threads(), omp_get_thread_num());
omp_set_num_threads(2);
#pragma omp parallel 
{
int x;
printf("%p\t%p\n",&x,&y);
dernierThread = omp_get_thread_num();
nombreThread = omp_get_num_threads();
}
}
printf("Il y a eu %d threads en paral, et le dernier etait le no. : %d\n\n", nombreThread, dernierThread);
printf("%d seul thread, pas parallele\n", omp_get_num_threads());
printf("thread no. %d\n", omp_get_thread_num());
}
// numero thread apparaissent ordre random (3,1,2) (3,2,1) (1,3,2)
// si variable declaree avant pragma, non stockee dans pragma; si dans pragma, stockee dans pragma