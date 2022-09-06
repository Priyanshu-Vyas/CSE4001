#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
omp_set_num_threads(atoi(argv[1]));
int r1,c1;
printf("Enter no of rows and columns of matrix 1:");
scanf("%d%d",&r1,&c1);
int mat1[r1][c1];
printf("Enter Matrix 1:\n");
for(int i=0;i<r1;i++)
{
    for(int j=0;j<c1;j++)
    {
        scanf("%d",&mat1[i][j]);
    }
}
int r2,c2;
printf("Enter no of rows and columns of matrix 2:");
scanf("%d%d",&r2,&c2);
int mat2[r2][c2];
printf("Enter Matrix 2:\n");
for(int i=0;i<r2;i++)
{
    for(int j=0;j<c2;j++)
    {
        scanf("%d",&mat2[i][j]);
    }
}

if(c1!=r2)
{
    printf("Matrix Multiplication Not Possible!!");
    return 0;
}
int res[r1][c2];
for(int i=0;i<r1;i++)
{
    for(int j=0;j<c2;j++)
    {
        res[i][j]=0;
    }
}
clock_t t;
t=clock();
#pragma omp parallel for collapse(3)
for(int i=0;i<r1;i++)
{
    for(int j=0;j<c2;j++)
    {
        for(int k=0;k<c1;k++)
        {
            res[i][j]+=mat1[i][k]*mat2[k][j];
        }
    }
}
t=clock()-t;
printf("Resultant Matrix:\n");
for(int i=0;i<r1;i++)
{
    for(int j=0;j<c2;j++)
    {
        printf("%d ",res[i][j]);
    }
    printf("\n");
}

printf("Execution time is %lf ms.\n",(double)t/CLOCKS_PER_SEC);
}
