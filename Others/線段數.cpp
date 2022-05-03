#include "bits/stdc++.h"
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

using namespace std;

struct node{
    int l,r;
    int val;
};

array<node,2000000> tree;
vector<int> v;

void pull(int l,int r,int p){
    tree[p].val=max(tree[l].val,tree[r].val);
    return;
}

void build(int l,int r,int p){
    if(l==r){
        tree[p].val=v[l];
        return;
    }
    int m=(l+r)>>1;
    tree[p].l=l;
    tree[p].r=r;
    build(l,m,p<<1),build(m+1,r,(p<<1)+1);
    pull(p<<1,(p<<1)+1,p);
    return;

}

int query(int ql,int qr,int l,int r,int p){
    if(ql<=l&&r<=qr)return tree[p].val;
    int m=(l+r)>>1;
    if(qr<=m)return query(ql,qr,l,m,p<<1);
    if(ql>m)return query(ql,qr,m+1,r,(p<<1)+1);
    return max(query(ql,qr,l,m,p<<1),query(ql,qr,m+1,r,(p<<1)+1));
}

int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
       int x;
       cin>>x;
       v.push_back(x);
   }
   build(0,n-1,1);
   int m;
   cin>>m;
   for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        cout<<query(min(x,y)-1,max(x,y)-1,0,n-1,1)<<endl;
   }


   return 0;
}
