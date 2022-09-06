 #include<iostream>
using namespace std;
int main()
{
int cost[6][6],g1[8],g2[6][6],g3[6][6],v[5],minarr[8],visited[8];
int i,j,k,min,calc;
#pragma omp parallel for
for(i=1;i<=4;i++){
visited[i]=0;
}
for(i=1;i<=4;i++){
#pragma omp parallel for
for(j=1;j<=4;j++){
if(j==i){
cost[i][j]=0;
continue;

