#include "bits/stdc++.h"

using namespace std;

int mx[500000<<2]={};

 int query(int s,int t,int L,int R,int ans,int m){
    if(s==t) return mx[s+m];
    for(s+=m,t+=m;s^t^1;s>>=1,t>>=1){
        L+=mx[s],R+=mx[t];
        if(s&1^1) L=max(L,mx[s^1]);
        if(t&1) R=max(R,mx[t^1]);
    }
    for(ans=max(L,R),s>>=1;s;s>>=1) ans+=mx[s];
    return ans;
}
int main(){
    int n,m;
    cin>>n;
    for(m=1;m<=n;m<<=1);
    cout<<1;
    for(int i=m+1;i<m+n;i++){
        cin>>mx[i];
    }
    for(int i=m-1;i;i--){
        mx[i]=max(mx[i<<1],mx[i<<1|1]);
        mx[i<<1]-=mx[i],mx[i<<1|1]-=mx[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        cout<<query(min(x,y),max(x,y),0,0,0,m);

    }
    return 0;
}
