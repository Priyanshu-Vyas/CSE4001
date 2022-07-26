#include<stdio.h>
#include<omp.h>
int main()
{
omp_set_num_threads(6);
#pragma omp parallel
{
printf("HELLO WORLD!!");
}
}
