#include "bits/stdc++.h"
#define pb push_back
#pragma GCC optimize("Ofast,fast-math,unroll-loops")

using namespace std;



int main()
{
   int n;
   cin>>n;
   int a[n]={};
   int q;
   cin>>q;
    int con=n;
    for(int i=0;i<q;i++)
    {
        int r,l,k;
        cin>>r>>l>>k;
        if(l-r>n/2){
            if(k==1){
            for(int i=r-1;i<l;i++){
                if(a[i]==0)
                {
                    a[i]=1;
                    con--;
                }
            }
        }else{
        for(int i=r-1;i<l;i++){
                if(a[i]==1)
                {
                    a[i]=0;
                    con++;
                }
        }
    }

        }else{
        if(k==1){
            for(int i=r-1;i<l;i++){
                if(a[i]==0)
                {
                    a[i]=1;
                    con--;
                }
            }
        }else{
        for(int i=r-1;i<l;i++){
                if(a[i]==1)
                {
                    a[i]=0;
                    con++;
                }
        }
    }

        }cout<<con<<endl;
    }
   return 0;
}

