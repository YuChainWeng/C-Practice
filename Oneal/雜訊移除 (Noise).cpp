#include <iostream>

using namespace std;

int main()
{
   string s,p;
   int n;
   cin>>s>>n;
   for(int i=0;i<s.size();i++){
       if(s[i]-'0'!=n)p+=s[i];
   }
   n=p.size();
   if(n%2==1){
       bool b=true;
       for(int i=0,j=n-1;i<n/2;i++,j--){
           if(p[i]!=p[j]){
               b=false;
               break;
           }
       }
       if(n==1)b=true;
       if(b)cout<<"Yes";
       else cout<<"No";
   }else cout<<"No";
   return 0;
}
