#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int flag=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='H' || s[i]=='Q' || s[i]=='9' || s[i]=='!' ){
            flag=1;
            break;
        } 
    }
    if(flag==1) cout<<"YES";
    else cout<<"NO";

}