#include<stdio.h>
#include<omp.h>
int main()
{
#pragma omp parallel for
for(int i=0;i<10;i++)
printf("HELLO WORLD!! %d \n",omp_get_thread_num());
}
