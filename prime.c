#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>


int isPrime(int n)
{
   int flag=0;
   
   for(int i=2;i<=n/2;i++)
   {
       if(n%i==0)
       {
         flag=1;
         break;
       }
   
   }
   
   if(flag==1)return -1;
   
   return 1;
 
}

int numberOfPrime(int n)
{
  
  int count=0;
  
  # pragma omp parallel reduction(+:count)
  for(int i=2;i<=n;i++)
  {
    if(isPrime(i)==1)count++;
  }
  return count;

}

void numberOfPrimesDynamic(int n,int numberThreads)
{
  
   int count=0;
   
   clock_t start,end;
   double executionTime;
   
   start=clock();
   
   omp_set_num_threads(numberThreads);
   
   int nthread;
   
   #pragma omp parallel
   {
     nthread=omp_get_num_threads();
   }
   
    
   #pragma omp parallel for  schedule(dynamic,3)
   
   for(int i=0;i<=n;i++)
   {
      int l=pow(2,i);
      
      int count= numberOfPrime(l);
      
  
      
       printf("The number of prime numbers between 2 to %d is: %d\n",l,count);
      
     
   }
   
   
   end=clock();
   
   executionTime=(double)(end-start)/CLOCKS_PER_SEC;
   
   
   printf("The execution time of the program for %d threads is %f\n",nthread,executionTime);
   
   
}

void numberOfPrimesStatic(int n,int numberThreads)
{
  
   int count=0;
   
   clock_t start,end;
   double executionTime;
   
   start=clock();
   
   omp_set_num_threads(numberThreads);
   
   int nthread;
   
   #pragma omp parallel
   {
     nthread=omp_get_num_threads();
   }
   
    
   #pragma omp parallel for  schedule(static,3)
   
   for(int i=0;i<=n;i++)
   {
      int l=pow(2,i);
      
      int count= numberOfPrime(l);
      
  
      
       printf("The number of prime numbers between 2 to %d is: %d\n",l,count);
      
     
   }
   
   
   end=clock();
   
   executionTime=(double)(end-start)/CLOCKS_PER_SEC;
   
   
   printf("The execution time of the program for %d threads is %f\n",nthread,executionTime);
   
   
}


void numberOfPrimesGuided(int n,int numberThreads)
{
  
   int count=0;
   
   clock_t start,end;
   double executionTime;
   
   start=clock();
   
   omp_set_num_threads(numberThreads);
   
   int nthread;
   
   #pragma omp parallel
   {
     nthread=omp_get_num_threads();
   }
   
    
   #pragma omp parallel for  schedule(guided,3)
   
   for(int i=0;i<=n;i++)
   {
      int l=pow(2,i);
      
      int count= numberOfPrime(l);
      
  
      
       printf("The number of prime numbers between 2 to %d is: %d\n",l,count);
      
     
   }
   
   
   end=clock();
   
   executionTime=(double)(end-start)/CLOCKS_PER_SEC;
   
   
   printf("The execution time of the program for %d threads is %f\n",nthread,executionTime);
   
   
}

int main()
{
  printf("\nDYNAMIC\n\n");
   numberOfPrimesDynamic(17,4);
   
   printf("\nSTATIC\n\n");
   
   numberOfPrimesStatic(17,4);
   
   printf("\nGUIDED\n\n");
   numberOfPrimesGuided(17,4);
}
