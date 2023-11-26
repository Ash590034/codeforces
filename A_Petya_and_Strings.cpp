#include <bits/stdc++.h>
using namespace std;



int main(){
   string s1,s2;
   cin>>s1>>s2;int ans=0;

   for(int i=0;i<s1.size();i++){
    if((tolower(s1[i])).compare(tolower(s2[i]))!=0){
        ans=(tolower(s1[i])).compare(tolower(s2[i]));
        break;
    }

   }
   cout<<ans<<endl;
  



    return 0;
}
