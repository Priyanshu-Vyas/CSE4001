#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

int main(int argc,char *argv[])
{
  clock_t t;
  int list[1000];
  for(int i=0;i<1000;i++)
  {
    list[i]=rand()%10000;
  }
  t=clock();
  #pragma omp parallel for collapse(2)
  for(int i=0;i<1000;i++)
  {
    for(int j=i+1;j<1000;j++)
    {
      if(list[i]>list[j])
      {
        int temp=list[i];
        list[i]=list[j];
        list[j]=temp;
      }
    }
  }
  t=clock()-t;
  for(int i=0;i<1000;i++)
  {
    printf("%d ",list[i]);
  }
  printf("\n\n Execution Time: %lfms \n\n",(double)t/CLOCKS_PER_SEC);
}
