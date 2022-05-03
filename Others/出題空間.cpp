#include <iostream>

using namespace std;

int main()
{
   long long n,m,k;
   cin>>n>>m>>k;
   long long x;
   if(n%2==1)x=n*m;
   else x=(n-1)*m+1;
   int point[k];
   for(int i=0;i<k;i++){
       int N,M;
       cin>>N>>M;
       point[k]=n*(N-1)+M;
   }
   int step = 0,now = 0,kpoint = 0;
   while(now<=x){
       for(int i=6;i>=0;i++){
           if((now+i)!=point[kpoint]){
               now+=i;
               step++;
               break;
           }
           if(i==0)step=-1;
       }
       if(step==-1)break;
   }
   cout<<step<<endl;;
   
   return 0;
}