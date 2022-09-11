#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

int main(int argc,char *argv[])
{
  clock_t t;
  t=clock();
  omp_set_num_threads(atoi(argv[1]));
  #pragma omp parallel
  {
    #pragma omp master
    {
      printf("Mater Thread number: %d \n",omp_get_thread_num());
    }
  }
  t=clock()-t;
  printf("Execution Time: %lfms. \n",(double)t/CLOCKS_PER_SEC);
}
