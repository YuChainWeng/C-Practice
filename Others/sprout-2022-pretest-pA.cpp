#include <iostream>
#include <map>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    map<int,int> mp;
    int n,m,k,tol;
    cin>>n>>m>>k;
    tol=n*m;
    tol++;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        mp[(x-1)*m+y]++;
    }
    int tolstep = 0 ;
    int now=0;
    int b=0;
    if(mp.find(tol)==mp.end()){
    while(1){
        for(int i=6;i>0;i--){
            if(mp.find(now+i)==mp.end()&&now+i<=tol){
                now+=i;
                tolstep++;
                break;
            }
            if(i==1)b=1;
        }
      // cout<<now<<"　";
        if(b==1)break;
        if(now==tol)break;
    }
    if(k==0){
        if(tol%6==0)tolstep=tol/6;
        else tolstep=tol/6+1;
    }
    if(b==1)cout<<-1<<endl;
    else cout<<tolstep;
    }else cout<<-1<<endl;
    return 0;
}
