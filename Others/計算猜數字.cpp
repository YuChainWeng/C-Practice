#include "bits/stdc++.h"

using namespace std;

int main (){
    while(1){
    bool b=1;
    cout<<"輸入數字:(結束輸入0)";
    string yous;
    cin>>yous;
    while(b){
        string nows;
        cout<<"對方猜:";
        cin>>nows;
        if(nows.size()==1)b=0;
        int counta=0,countb=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(yous[i]==nows[j]){
                    if(i==j)counta++;
                    else countb++;
                }
            }
        }
        cout<<counta<<"A"<<countb<<'B'<<endl;
        if(counta==4){
            cout<<"結束";
            break;

        }
    }
    cout<<"是否重新 y/n";
    char ch;
    cin>>ch;
    if(ch=='n')break;
    }

    return 0;
}
