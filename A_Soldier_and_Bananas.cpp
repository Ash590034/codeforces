#include <bits/stdc++.h>
using namespace std;
int main(){
    long long c,m,n;
    cin>>c>>m>>n;
    long long moneyReq=(n*(n+1)/2)*c;
    if(m>=moneyReq) cout<<0;
    else{ cout<<moneyReq-m;}
   

    return 0;
}