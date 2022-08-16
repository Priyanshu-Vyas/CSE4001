#include<stdio.h>
#include<omp.h>
#include<time.h>

int main()
{
    clock_t start,end;
    int n;
    scanf("%d",&n);
    int no_of_threads;
    scanf("%d",&no_of_threads);
    omp_set_num_threads(no_of_threads);
    int sum=0;
    start=clock();
    #pragma omp parallel for reduction(+:sum)
    for(int i=1;i<=n;i++) {
        sum+=i;
    }
    end=clock();
    printf("%d\n",sum);
    printf("%f",(double)(end-start)/CLOCKS_PER_SEC);
}
