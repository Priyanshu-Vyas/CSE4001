#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

int main(int argc,char* argv[])
{
  omp_set_num_threads(atoi(argv[1]));
  clock_t t;
  t=clock();
  
  int j=0,x;
  int a[11]={-1,1,2,3,4,5,6,7,8,9,10};
  int b[11];
  #pragma omp parallel for firstprivate(j) lastprivate(x)
  for(int i=1;i<=10;i++)
  {
      if(i==1||i==10)
      {
        j=j+1;
      }
      a[i]=a[i]+j;
      x=a[i];
      b[i]=(x*x);
  }
  t=clock()-t;
  for(int i=1;i<=10;i++)
  {
    printf("%d ",a[i]);
  }
  printf("\n");
  for(int i=1;i<=10;i++)
  {
    printf("%d ",b[i]);
  }
  printf("\nExecution Time: %lfms. \n",(double)t/CLOCKS_PER_SEC);
}
