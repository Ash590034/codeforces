#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int ans=0;
    while(n--){
        int p,c;
        cin>>p>>c;
        if(c-p>=2) ans++;

    }
    cout<<ans;
    
    
    

    

    return 0;

}