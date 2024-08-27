#include <bits/stdc++.h> 
using namespace std;
void solve(){
    function<bool(int)> help=[&](int mid){
        cout<<"? 1 "<<mid<<endl;
        cout.flush();
        int out;
        cin>>out;
        return mid==out;
    };
    int low=2 , high=999;
    for(int i=0;i<10;i++){
        int mid=(low+high)/2;
        bool f=help(mid);
        if(f) low=mid+1;
        else high=mid;
    }
    cout<<"! "<<high<<endl;
    cout.flush();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}