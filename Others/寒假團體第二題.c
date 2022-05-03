#include "bits/stdc++.h"
#define pb push_back
using namespace std;

array<vector<int>,20000> con;
array<int,200000> mx={};
array<int,200000> vis={};

void bfs(int now,int cb,int cw){
    queue<int> q;
    q.push(now);
    while(q.size()>0){
        int fr=q.front();
        q.pop();
        vis[fr]++;
        if(con[fr]==1)cb++;
        else cw++;
        int o=abs(cb-cw);
        if(mx[now]<o&&cb!=0&&cw!=0)mx[now]=o;
        for(int i=1;i<con[fr].size();i++){
            if(vis[con[fr][i]]==now)q.push(con[fr][i]);
        }
    }
    return;
}

int main()
{
   int n;
   cin>>n;

   for(int i=0;i<n;i++){
       int x;
       cin>>x;
       con[i].pb(x);
   }
   for(int i=0;i<n-1;i++){
       int x,y;
       cin>>x>>y;
       con[y-1].pb(x-1);
       con[x-1].pb(y-1);
   }
   for(int i=0;i<n;i++){
       bfs(i,0,0);
   }
   for(int i=0;i<n;i++){
       cout<<mx[i]<<' ';//     2 2 2 2 2 1 1 0 2
   }

   return 0;
}
