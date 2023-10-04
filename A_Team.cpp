#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans=0;

    while(t--){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1 && (y==1 || z==1)) ans+=1;
        else if(y==1 && (z==1)) ans+=1;
        


    }
    cout<<ans;

    return 0;
}