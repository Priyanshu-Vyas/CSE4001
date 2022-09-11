#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

int main(int argc,char* argv[])
{
  omp_set_num_threads(atoi(argv[1]));
  clock_t t;
  t=clock();
  #pragma omp parallel
  {
    printf("Parallel-Message\n");
    #pragma omp single
    {
      printf("Single-Message\n");
    }
  }
  t=clock()-t;
  printf("Execution Time: %lfms. \n",(double)t/CLOCKS_PER_SEC);
}
