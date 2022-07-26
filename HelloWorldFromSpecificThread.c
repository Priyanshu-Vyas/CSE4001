#include<stdio.h>
#include<omp.h>
int main()
{
int nthreads,Tid;
#pragma omp parallel
{
nthreads=omp_get_num_threads();
Tid=omp_get_thread_num();
if(Tid==5)
    printf("HELLO WORLD!! from thread %d out of %d threads\n",Tid,nthreads);
}
}
