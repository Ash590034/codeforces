#include <bits/stdc++.h>
using namespace std;
int main(){
    long long x;
    cin>>x;
    int ans=0;

    while(x){
        if(x%10==7 || x%10==4) ans++;
        x/=10;
        
        
        
        

       
        


    }
    if(ans==4 || ans==7) cout<<"YES";
    else cout<<"NO";

    return 0;
}