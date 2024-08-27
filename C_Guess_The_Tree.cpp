#include <bits/stdc++.h> 
using namespace std;
void solve(){
    function<int(int,int)> help=[&](int  a,int b){
        cout<<"? "<<a<<" "<<b<<endl;
        cout.flush();
        int out;
        cin>>out;
        return out;
    };
    int n;
    cin>>n;
    set<pair<int,int>> edges;
    for(int i=0;i<n-1;i++){
        int a=i+2 , b=1;
        while(true){
            int res=help(a,b);
            if(res==a){
                edges.insert({a,b});
                break;
            }
            b=res;
        }
    }
    cout<<"! ";
    for(auto it:edges) cout<<it.first<<" "<<it.second<<" ";
    cout<<endl;
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