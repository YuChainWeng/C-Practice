#include <iostream>

using namespace std;

int main()
{
   int n,m, k;
   cin>>n>>m>>k;
   int tol;
   if(n%2==1)tol=n*m;
   else tol=n*m-m+1;
   int a[tol]={};
   for(int i=0;i<k;i++){
       int x,y;
       cin>>x>>y;
       a[x*m+y-1-1]=-1;
       
   }
   for(int i=0;i<6;i++){
       if(a[i]==-1)continue;
       a[i]=1;
   }
   if(tol<6)cout<<1;
   else for(int i=6;i<tol;i++){
       if(a[i]==-1)continue;
       int min=99999999;
       for(int j=i-6;j<i;j++){
           if(a[j]<min&&a[j]>0)min=a[j];
       }
       a[i]=min+1;
   }
   cout<<a[tol-1];
   return 0;
}