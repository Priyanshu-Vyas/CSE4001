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
        }
    }
    return (flag==0)? true:false;
}

int noofprimes(int n)
{
    int cnt=0;
    #pragma omp parallel for schedule(dynamic) reduction(+:cnt)
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
    int N;
    printf("Enter power of 2: ");
    scanf("%d",&N);
    int nthreads=atoi(argv[1]);
    omp_set_num_threads(nthreads);
    time=clock();
    printf("Total no. of prime numbers between 2 to %lf = %d \n",pow(2,N),noofprimes(pow(2,N)));
    time=clock()-time;
    double t=(double)time/CLOCKS_PER_SEC;
    printf("Execution Time = %lf \n",t);
    return 0;
}
