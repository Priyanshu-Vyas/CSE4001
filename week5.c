#include<stdio.h>
#include<omp.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

bool prime(int x)
{
    int flag=0;
    for(int i=2;i<=x/2;i++)
    {
        if(x%i==0)
        {
            flag=1;
            break;
        }
    }
    return (flag==0)? true:false;
}

int noofprimes(int n)
{
    int cnt=0;
    #pragma omp parallel for reduction(+:cnt)
    for(int i=2;i<=n;i++)
    {
        if(prime(i))
        {
            cnt++;
        }
    }
    return cnt;
}

int main(int argc,char *argv[])
{
    clock_t time;
    /*int N;
    printf("Enter power of 2: ");
    scanf("%d",&N);*/
    int nthreads=atoi(argv[1]);
    omp_set_num_threads(nthreads);
    time=clock();
    printf("\n--------Static Thread Scheduling--------\n");
    #pragma omp parallel for schedule(static,3)
    for (int i=0;i<18;i++)
    {
      printf("Total no. of prime numbers between 2 to %d = %d \n",(int)pow(2,i),noofprimes(pow(2,i)));
    }
    time=clock()-time;
    double t=(double)time/CLOCKS_PER_SEC;
    printf("Execution Time = %lfms \n",t);
    time=clock();
    printf("\n--------Dynammic Thread Scheduling--------\n");
    #pragma omp parallel for schedule(dynamic,3)
    for (int i=0;i<18;i++)
    {
      printf("Total no. of prime numbers between 2 to %d = %d \n",(int)pow(2,i),noofprimes(pow(2,i)));
    }
    time=clock()-time;
    t=(double)time/CLOCKS_PER_SEC;
    printf("Execution Time = %lfms \n",t);
    time=clock();
    printf("\n--------Guided Thread Scheduling--------\n");
    #pragma omp parallel for schedule(guided,3)
    for (int i=0;i<18;i++)
    {
      printf("Total no. of prime numbers between 2 to %d = %d \n",(int)pow(2,i),noofprimes(pow(2,i)));
    }
    time=clock()-time;
    t=(double)time/CLOCKS_PER_SEC;
    printf("Execution Time = %lfms \n",t);
    return 0;
}
