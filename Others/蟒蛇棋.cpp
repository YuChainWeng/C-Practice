#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
   long long n,m,k;
   long long step = 0,now = 0;
   cin>>n>>m>>k;
   long long x=n*m;
   map<int,int> point;
   for(int i=0;i<k;i++){
       int N,M;
       cin>>N>>M;
       if(N%2==0)point[(N-1)*m+(m-M+1)]++;
        else point[(N-1)*m+M]++;
   }
   if(k==0){
    step=x/6;
    if(x%6!=0)step++;
    now=x+1;
   }
   while(now<=x&&step!=-1){
       for(int i=6;i>=0;i--){
           if(i==0)step=-1;
           if(point[now+i]!=1){
               now+=i;
               step++;
               break;
           }
       }
   }
   cout<<step<<endl;

   return 0;
}
