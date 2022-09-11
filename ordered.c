#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

int main(int argc,char* argv[])
{
  omp_set_num_threads(atoi(argv[1]));
  clock_t t;
  t=clock();
  #pragma omp parallel for ordered
  for (int i=1;i<=10;i++)
  {
    #pragma omp ordered
    {
      printf("%d ",i);
    }
  }
  t=clock()-t;
  printf("\nExecution Time: %lfms. \n",(double)t/CLOCKS_PER_SEC);
}
