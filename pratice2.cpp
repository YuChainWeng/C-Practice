#include "iostream"

using namespace std;

int main(){
    long long n,m,k,told=0;
    cin>>n>>m>>k;
    while(k--){
        long long s1,s2,e1,e2,x1,x2;
        cin>>s1>>s2>>e1>>e2>>x1>>x2;
        if(s1==x1){
            if(x1==e1)told++;
            else if(x2==e2)told++;
        }
        else if(x2==s2){
            if(x2==e2)told++;
            else if(x1==e1)told++;
        }
    }
    cout<<told;

    return 0;
}