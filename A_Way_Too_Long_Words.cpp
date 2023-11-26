#include <bits/stdc++.h>
using namespace std;

string printAns(string s){
    if(s.size()<=10) return s;
    else{
        return (s[0]+to_string(s.size()-2)+s[s.size()-1]);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ans=printAns(s);
        cout<<ans<<endl;
       
    }

    return 0;
}
