#include<stdio.h>
#include<omp.h>
int main()
{
int n,sum=0;
printf("Enter n = ");
scanf("%d",&n);
#pragma omp parallel for
for(int i=1;i<=n;i++)
sum+=i;
printf("Sum = %d\n",sum);
}
