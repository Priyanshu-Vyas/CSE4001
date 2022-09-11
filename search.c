#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

int main(int argc,char *argv[])
{
  omp_set_num_threads(atoi(argv[1]));
  clock_t t;
  int list[1000];
  for(int i=0;i<1000;i++)
  {
    list[i]=rand()%2000;
  }
  t=clock();
  int flag=0;
  #pragma omp parallel for
  for (int i=0;i<1000;i++)
  {
    if(list[i]==10)
    {
      printf("Element found at position %d. \n",i+1); 
      flag=1;
    }
  }
  if(flag==0)
  {
    printf("Element not found in the list. \n"); 
  }
  t=clock()-t;
  printf("Execution Time: %lfms. \n",(double)t/CLOCKS_PER_SEC);
}
