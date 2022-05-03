#include "bits/stdc++.h"

using namespace std;

int main()
{
   long long x,y,n,m;
   random_device dev;
   mt19937 rng(dev());
   uniform_int_distribution<std::mt19937::result_type> dist100(1,100);
   cin>>n>>m;
   while(n--){
        cout<<"--"<<endl;
       long long out=0,in=0,c=m;
        double st=1.0000000;
       while(c--){
           x=dist100(rng);
           y=dist100(rng);
           if((x*x+y*y)>(100*100))out++;
           else in++;
       }
       double d=(((4*in)*st)/((out+in))*st);
       cout<<in<<' '<<out<<' '<<d<<endl;
   }
   return 0;
}
