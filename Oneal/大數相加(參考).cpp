#include "bits/stdc++.h"

using namespace std;

int main()
{
   string a,b;
   cin>>a>>b;
   int mx=max(a.size(),b.size());
   int aa[mx]={},bb[mx]={},cc[mx]={};
   for(int i=mx-1,j=a.size()-1;j>=0&&i>=0;i--,j--){
       aa[i]=a[j]-'0';
   }
   for(int i=mx-1,j=b.size()-1;j>=0&&i>=0;i--,j--){
       bb[i]=b[j]-'0';
   }
   bool nxt=false;
   for(int i=mx-1;i>=0;i--){
       int x=aa[i]+bb[i];
       if(nxt)x++;
       if(x>=10){
           x-=10;
           cc[i]=x;
           nxt=true;
       }else {
           nxt=false;
           cc[i]=x;
       }
   }
   for(int i=0;i<mx;i++){
        cout<<cc[i];
   }

   return 0;
}
